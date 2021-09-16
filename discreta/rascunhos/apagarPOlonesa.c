#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */


int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */





int main(void)
{
    int type;
    double op2, n1, n2;
    char s[MAXOP];

    printf("Calculadora polonesa pos-fixa \n");


    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
            push(atof(s));
            break;
            case '+':
            n1 = pop();
			n2 = pop();
			push(n2 + n1);
            printf("voce digitou %.2lf\n", n2);
			printf("voce digitou %.2lf\n", n1);
			break;
            case '*':
            n1 = pop();
            n2 = pop();
            push(n2 * n1);
            printf("voce digitou %.2lf\n", n2);
            printf("voce digitou %.2lf\n", n1);
            break;
            case '-':
         // op2 = pop();
            n1 = pop();
            n2 = pop();
            push(n2 - n1);
            printf("voce digitou %.2lf\n", n2);
            printf("voce digitou %.2lf\n", n1);
            break;
            case '/':
        //  op2 = pop();
            n1 = pop();
            n2 = pop();
            push(n2 / n1);
            printf("voce digitou %.2lf\n", n2);
            printf("voce digitou %.2lf\n", n1);
            break;//
            case 'q':
            return 0;//
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
            case '\n':
            printf("Resultado: %.2lf\n\n", pop());
            break;
            default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

//   return EXIT_SUCCESS;
}




#define MAXVAL 100

int sp = 0;
double val[MAXVAL]; // 1

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("erro: pilha cheia, não é possível empurrar %g\n",f);
}

double pop(void)  // 2
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("erro: pilha vazia\n");
        return 0.0;
    }
}






#include<ctype.h> // 3

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';

    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;






    // coloquei chaves nesse if
    if(c=='-')
    {    if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    }
    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;

    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}






#define BUFSIZE 100 //4

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: muitos caracteres\n");
    else
        buf[bufp++] = c;
}

