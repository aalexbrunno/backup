#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
     char pais[300] = {0};

     printf(" digite em qual pais voce estuda\n");

     //scanf(" %c, pais);
     
    
   	setbuf(stdin, 0);
     
    fgets(pais, 300, stdin);

//     if(pais == 'brasil')
//     {
//         printf(" parabens\n");

    pais[strlen(pais)-1] = '\0';

    
    for(int i =0; i <= 299; i++)
    {    if(pais[i] == 'b','r','a','s','i','l')
            {printf(" parabens\n");}

         else
            {printf(" pesames\n");}
    }
//    printf(" o pais eh %s\n",pais );

 //    }

//     else 
//     {   printf(" meus pesames");

//     }




   return 0;

}
