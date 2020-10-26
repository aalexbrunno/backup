#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char*clone = "#include <stdio.h>%c#include <stdlib.h>%c%cint main(void)%c{%c%c%c%c%c%cchar*clone = %c%s%c;%c%c%c%c%c%cprintf(clone,10,10,10,10,10,32,32,32,32,34,clone,34,10,10,32,32,32,32,10,10,10,10);%c%creturn 0;%c}%c";

    printf(clone,10,10,10,10,10,10,32,32,32,32,34,clone,34,10,10,32,32,32,32,10,10,10,10);

return 0;
}
