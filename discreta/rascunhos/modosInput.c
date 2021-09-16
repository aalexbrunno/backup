#include <ncurses.h>
#include <stdio.h>

int main(){
    //iniciando ncurses
    initscr();
    noecho();

    //Modos de input:
    //cbreak();
    //halfdelay(10);
    //nodelay(stdscr, true);
    timeout(100);
    int ch;

    while((ch = getch()) != 10) //fica imprimindo ate que aperte enter
    {
        printw("%d\n", ch);
    }

    endwin();
    return 0;
}

