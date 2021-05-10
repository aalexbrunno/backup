 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #include<unistd.h>
 #include<string.h>

int main(void)
{
 char a[50] = {0};
 char b[50] = {0};
 char c[50] = {0};
 char d[50] = {0};
 char e[50] = {0};
 char f[50] = {0};
 int i = 0,j = 0;
 int vetor[2] = {0};
// char vetor[6] = {0};
 char matriz[2][2] = {0};


 printf("escreva 6 nomes\n");

/*
setbuf(stdin, 0);
fgets(a, 255, stdin);
fgets(a, 255, stdin);

setbuf(stdin, 0);
fgets(b, 255, stdin);
fgets(b, 255, stdin);
*/

 
 
/* 
 scanf(" %[^\n]s", a);
 scanf(" %[^\n]s", b);
 scanf(" %[^\n]s", c);
 scanf(" %[^\n]s", d);
 scanf(" %[^\n]s", e);
 scanf(" %[^\n]s", f);
*/
  
 
 printf("\n");

 for(i =0; i < 2; i++)
 {
    for(j =0; j < 2; j++)
    {
       scanf(" %s", matriz[i][j]);   
    
    }
 }


   for(i =0; i < 2; i++)
   {
        for(j =0; j < 2; j++)
        {
            printf(" %s", matriz[i][j]);

        }
   }



  
  
  
  
/*  
  for(i = 0; i <= 0; i++)
 {
     vetor[i] = rand() % 13;

//      printf("valor de i  eh %d \n",i);


 }

*/








  return 0;
}
