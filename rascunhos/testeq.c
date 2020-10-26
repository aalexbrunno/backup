#include<stdio.h>

int main(void)
{
char*quine = "#include<stdio.h>%c%cint main(void)%c{%cchar*quine = %c%s%c;%c%cprintf(quine,10,10,10,10,34,quine,34,10,10,10,10,10,10);%c%creturn 0;%c}%c";

printf(quine,10,10,10,10,34,quine,34,10,10,10,10,10,10);

return 0;
}
