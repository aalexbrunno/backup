#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct var {
    char **info;
}var_t;

var_t trimStr(char *str);

int main(void)
{
    // char *str = (char*)calloc(100, sizeof(char));
    char str[150] = "4;eduardo;um titulo;nenhum;10;uma editora;1;2020";
    var_t r = trimStr(str);
    for(int i = 0; i <8;i++)
    {
        printf("%s\n", r.info[i]);
    }
    
    /*
     for(int i=0;i<8;i++)
     {
         free(r.info[i]);
     }
    free(r.info);
   */
    return 0;
}

var_t trimStr(char *str)
{
    int i=0;
    var_t infos;
    infos.info  = (char**)calloc(8, sizeof(char*));

    for(i=0;i<8;i++)
    {
        infos.info[i] = (char*)calloc(100, sizeof(char));
    }

    char *token = strtok(str,";");
    i=0;
    while( token != NULL )
    {
        // printf( " %s\n", token );
        infos.info[i] = token;
        i++;
        
        token = strtok(NULL, ";");
    }
    return infos;
}


// void breakStr(char *str)
// {
//     int flags = 0, n=0;

//     for(int i=0;*(str+i) != '\0';i++)
//     {
//         if(*(str+i)==';')
//         {

//         }
//     }
// }
