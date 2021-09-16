#include <stdio.h>
#include <ncurses.h>
//using namespace std;

int main(int argc, char argv)
{
   initscr();
   
   int x,y;
   x = 60;
   y = 20;

   move(y,x);

  // printw = ("nunca desista");



   printw("ola mundo");
   int c = getch();

   clear();

   move(0,0);

   printw("%d",c);
   refresh();

   getch();

   endwin();





    return 0;
}
