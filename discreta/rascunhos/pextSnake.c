//Jogo pext snake para estudos sobre logica de programacao e Ncurses

#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 36007 //delay to loop de jogo 
#define TIMEOUT 10 //tempo de buffer em milissegundos que o buffer espera

/* Global Vars */
	typedef enum {
		LEFT,  //1
		RIGHT, //2
		UP, //3
		DOWN //4
	} direction_type; // enumeracao das direcoes 

	typedef struct point {
		int x;
		int y;
	} point; // conjunto de coordenadas no grid

	int x = 0, // localizacao X
		y = 0, //localizacao Y 
		maxY = 0, // maximo Y
		maxX = 0, // maximo X
		nextX = 0, // armazena a proxima coordenada X
		nextY = 0, // armazena a proxima coordenada Y 
		
		tailLength = 5, //quantidade de partes no corpo da cobra
		score = 0, // pontuacao
        play = 0, //estado de jogo 0 jogo nao iniciado, 1 iniciado,2 tela de creditos, 3 sair do jogo
        destaque = 0;

    //flags de gameOver e pauseGame
	bool gameOver = false;
	bool pauseGame = false;

	direction_type currentDir = RIGHT; 
	point snakeParts[255] = {}; //vetor que guarda as partes do snake
	point food;

/*Prototype*/

void init(); //Inicia ou reseta o jogo
void cursesInit(); //iniciar Ncurses
void createFood(); //Cria um ponto aleatorio no mapa para a comida
void drawPart(point drawPoint); //imprime um ponto na posicao desejada
void shiftSnake(); //desembaralha a cobra
void drawScreen(); //imprime os menus e o jogo trabalha ao lado do loop principal


/* Functions */

 // inicia o jogo ou reseta o mesmo
	void init() {
		srand(time(NULL));

		currentDir = RIGHT;// inicia olhando para direita
		tailLength = 5; // tamanho 5 da cobra
		gameOver = false; // nao teve game over
		score = 0; // zera o placar

		clear(); // Limpa a tela
		
		//Cordenadas iniciais  
		int j = 0;
		for(int i = tailLength; i >= 0; i--) { 
			point currPoint;
			
			currPoint.x = i;
			currPoint.y = maxY / 2; //Start mid screen on the y axis

			snakeParts[j] = currPoint;
			j++;
		}

        // coloca a comida 
		createFood();
		box(stdscr,0,0);
		refresh(); //atualiza a tela
	}

	

	void cursesInit() {
		initscr(); // inicia a janela principal do ncurses (stdscr)
		noecho(); // Nao retornar inputs 
		keypad(stdscr, TRUE); // Receber entrada das setinhas
		
		cbreak(); // tempo imediato de resposta do ctrl+c 
		timeout(TIMEOUT); /*evita que a funcao getch seja um bloqueio e envia ERR
	    no buffer de input e por isso o programa continua rodando*/
		curs_set(FALSE); //Nao mostra o cursor
        start_color();//inicia as cores
        //pares de cores
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_RED, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);


		//Receber o tamanho maximo do terminal
		getmaxyx(stdscr, maxY, maxX);
	}

    void createFood() {
		//ponto aleatorio onde a comida vai aparecer entre a coordenada x = 10 e x = maxX -10
		food.x = (rand() % (maxX - 20)) + 10;

		//Ponto entre y = 5 e y = maxY - 5
		food.y = (rand() % (maxY - 10)) + 5; 
	}

	//foncao que imprime a posicao de um objeto recebendo dados do struct referente ao objeto
	void drawPart(point drawPoint) {
		mvprintw(drawPoint.y, drawPoint.x, "*");
	}

    // desembaralhar a cobra
	void shiftSnake() {
		point tmp = snakeParts[tailLength - 1]; //guardar a posiçao da tail

		for(int i = tailLength - 1; i > 0; i--)  {//viajar ate a cabeça desembaralhando a cobra   
			snakeParts[i] = snakeParts[i-1];
		}

		snakeParts[0] = tmp;
	}

    //Funções principais 
	void drawScreen() {

		// Limpa a tela e imprime as coisas novamente
		// Caso modifique coloque onde imprimir aqui
		clear(); 

        // menu de inicio do jogo 
        if(play == 0){
            attron(COLOR_PAIR(2));
            attron(A_BOLD);
            mvprintw(maxY/2, maxX/2-11, "PEXT SNAKE:");
            attroff(COLOR_PAIR(2));
            attroff(A_BOLD);

            for(int i =0; i < 3; i++)
            {   if(destaque == i) attron(A_REVERSE);
                if(i == 0)mvprintw(maxY/2 + 1, maxX/2 - 11, "Jogar");
                if(i == 1)mvprintw(maxY/2 + 2, maxX/2 - 11, "Controles");
				 if(i == 2)mvprintw(maxY/2 + 3, maxX/2 - 11, "Sair do Jogo");
                attroff(A_REVERSE);
            }
        }

        //Menu de Controles
		if(play == 2){
            attron(COLOR_PAIR(2));
            attron(A_BOLD);
            mvprintw(maxY/2, maxX/2-11, "CONTROLES:");
            mvprintw(maxY/2 + 1, maxX/2 - 11, "use as setas para se mover");
            mvprintw(maxY/2 + 2, maxX/2 - 11, "p para pausar");
			mvprintw(maxY/2 + 3, maxX/2 - 11, "enter para sair dessa tela");
            attroff(COLOR_PAIR(2));
            attroff(A_BOLD);
        }

        //Menu de pausa
		if(pauseGame){
			attron(A_BOLD);
			attron(COLOR_PAIR(2));
		    mvprintw((maxY/2), ((maxX/2)-12), "Jogo Pausado");
            attroff(A_BOLD);
			attroff(COLOR_PAIR(2));

			for(int i =0; i < 3; i++)
            {   if(destaque == i) attron(A_REVERSE);
                if(i == 0)mvprintw(maxY/2 + 1, maxX/2 - 12, "Resumir");
                if(i == 1)mvprintw(maxY/2 + 2, maxX/2 - 12, "Reiniciar");
				 if(i == 2)mvprintw(maxY/2 + 3, maxX/2 - 12, "Sair do Jogo");
                attroff(A_REVERSE);
            }
			
		} 

        // menu de game over
		if(gameOver){
			attron(A_BOLD);
			attron(COLOR_PAIR(2));
		    mvprintw((maxY/2), ((maxX/2)-11), "GAME OVER");
			mvprintw((maxY/2 + 1), ((maxX/2)-18), "Deseja jogar novamente?");
            attroff(A_BOLD);
			attroff(COLOR_PAIR(2));

			for(int i =0; i < 2; i++)
            {   if(destaque == i) attron(A_REVERSE);
                if(i == 0)mvprintw(maxY/2 + 2, maxX/2 - 11, "SIM");
                if(i == 1)mvprintw(maxY/2 + 2, maxX/2 - 5, "NAO");
                attroff(A_REVERSE);
            }
			
		}

        //Loop de jogo
		if(play == 1){

		//Imprime a cobra 
		for(int i = 0; i < tailLength; i++) {
			attron(A_BOLD);
			attron(COLOR_PAIR(1));
			drawPart(snakeParts[i]); // imprime cada pedaco da cobra 
			attroff(COLOR_PAIR(1));
			attroff(A_BOLD);
		}

		//imprime a comida		
		attron(COLOR_PAIR(2));
		drawPart(food);
        attroff(COLOR_PAIR(2));
		
		//Imprime o score
		attron(A_BOLD);
        attron(COLOR_PAIR(3));
	 	box(stdscr, 0, 0);
		mvprintw(0, 2, "Score: %i", score);
		attroff(COLOR_PAIR(3));
	    attroff(A_BOLD);
	 	
		}

		//refresh
		refresh();

		//Delay de jogo (para nao fritar o processador)
		usleep(DELAY); 
	}

/* Main */
	int main(void) 
    {
		cursesInit();

        int i;
		int ch; //caracter 
		

		while(1) //Loop de jogo
        {
			getmaxyx(stdscr, maxY, maxX);
			
            //os loops de inputs alteram flags e estados de jogo 
			//inputs do menu de inicio do jogo 			
			while(play == 0)
    	    {  
               drawScreen();
               ch = getch();
               switch(ch)
                {
                    case KEY_UP:
                        destaque--;
                        if(destaque <= -1)
                            destaque = 0;
                     break;

                     case KEY_DOWN:
                        destaque++;
                         if(destaque >= 3)
                        destaque = 2;
                    break;

                    default:
                    break; 
                }
                if(ch == 10 && destaque == 0) //jogar
                {
                    play = 1;
					init();
                    clear();
                    break;
                }
				if(ch == 10 && destaque == 1) //controles
                {
                    play = 2;
                    clear();
                    break;
                }
                if(ch == 10 && destaque == 2) //sair
                {
                    play = 3;
                    clear();
                    break;
                }
				usleep(DELAY);
            }
            //inputs do menu controles
			while(play == 2)
			{   
				drawScreen();
				ch = getch();
				if(ch == 10)
				{ 
				clear();
				play = 0;
				break;
				}
				usleep(DELAY);
				
			}

            //inputs do menu de pause
			while(pauseGame){
				drawScreen();
               ch = getch();
               switch(ch)
                {
                    case KEY_UP:
                        destaque--;
                        if(destaque <= -1)
                            destaque = 0;
                     break;

                     case KEY_DOWN:
                        destaque++;
                         if(destaque >= 3)
                        destaque = 1;
                    break;

                    default:
                    break; 
                }
                if(ch == 10 && destaque == 0)
                {
                    
                    clear();
					pauseGame = false;
                    break;
                }
				if(ch == 10 && destaque == 1)
                {
                
                    clear();
					play = 0;
					pauseGame = false;
                    break;
                }
                if(ch == 10 && destaque == 2)
                {
                    play = 3;
                    clear();
                    break;
                }
				usleep(DELAY);
				
			}


			
	        //inputs menu de game over
			while(gameOver) {	
               drawScreen();
               ch = getch();
               switch(ch)
                {
                    case KEY_LEFT:
                        destaque--;
                        if(destaque <= -1)
                            destaque = 0;
                     break;

                     case KEY_RIGHT:
                        destaque++;
                         if(destaque >= 2)
                        destaque = 1;
                    break;

                    default:
                    break; 
                }
                if(ch == 10 && destaque == 0)
                {
					init();
                    break;
                }
                if(ch == 10 && destaque == 1)
                {
                    play = 3;
                    clear();
                    break;
                }
				usleep(DELAY);
				
			}

			if(play == 3)
			{   
				clear();
				endwin();
				return 0;
			}

			/* Input Handler */
				ch = getch(); 
                // Recebe entrada do jogador e verifica se é uma direcao valida 
				if((ch == KEY_RIGHT) && (currentDir != RIGHT && currentDir != LEFT)) {
					currentDir = RIGHT;
				} else if ((ch == KEY_LEFT) && (currentDir != RIGHT && currentDir != LEFT)) {
					currentDir = LEFT;
				} else if((ch == KEY_DOWN) && (currentDir != UP && currentDir != DOWN)) {
					currentDir = DOWN;
				} else if((ch == KEY_UP) && (currentDir != UP && currentDir != DOWN)) {
					currentDir = UP;
				}
                
				//se o usuario apertar P entra no menu de pause
				if(ch == 'p') pauseGame = true;

			/* Movement */
			    // proximas posicoes para se mover
				nextX = snakeParts[0].x;
				nextY = snakeParts[0].y;

                //atualiza a posicao da cobra baseado na direcao 
				if(currentDir == RIGHT) nextX++;
		    	else if(currentDir == LEFT) nextX--;
				else if(currentDir == UP) nextY--;
				else if(currentDir == DOWN) nextY++;

                //verifica a colisao com a comida e faz com que a cobra cresca
				if(nextX == food.x && nextY == food.y) {
					point tail;
					tail.x = nextX;
					tail.y = nextY;
                    //o tamanho da cobra eh atualizado
					snakeParts[tailLength] = tail; 
                    
					if(tailLength < 255)
						tailLength++;
					else
						tailLength = 5; //Quando atingir o tamanho maximo volta para 5 pra subir mais ainda a pontuacao
                  
				    
					score += 5;
					createFood();

					/*para evitar que utilize um vetor extremamente 
					grande a condicao de vitoria do jogo original foi removida.
					uma alteracao seria armazenar as partes da cobra numa lista dinamica
					e verificar se o tamanho da cobra eh o mesmo da area jogavel menos 1*/

				} else {
					
					//game over se a cobra encostar em alguma parte dela mesma  
					for(i = 0; i < tailLength; i++) {
						if(nextX == snakeParts[i].x && nextY == snakeParts[i].y) {
							gameOver = true; 
							break;
						}
					}

			  		//Game Over se encostar na borda da tela
					if((nextX >= maxX || nextX < 0) || (nextY >= maxY || nextY < 0)) gameOver = true;
					
				
					//mover a cobra

					// cauda se torna a "cabeça"
					snakeParts[tailLength - 1].x = nextX;
					snakeParts[tailLength - 1].y = nextY;
				}

				//move as partes da cobra
				shiftSnake();

			/* imprime a tela */
				drawScreen();
				usleep(DELAY);
		}

	}

