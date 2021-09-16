#include "libABS.c"

int main(void) {
    

    char buffer[300] = " ";
    
    fgets(buffer, 300, stdin);
    
    reverte(buffer);
    
    printf("%s\n", buffer);
}
