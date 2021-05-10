 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #include<unistd.h>

int main(void)
{
 char a[50] = {0};
 char b[50] = {0};
 char c[50] = {0};
 char d[50] = {0};
 char e[50] = {0};
 char f[50] = {0};
 int i = 0;
 int vetor[1] = {0};
// char vetor[6] = {0};

 printf("escreva 6 nomes\n");

 scanf(" %[^\n]s", a);
 scanf(" %[^\n]s", b);
 scanf(" %[^\n]s", c);
 scanf(" %[^\n]s", d);
 scanf(" %[^\n]s", e);
 scanf(" %[^\n]s", f);

  printf("\n");

 for(i = 0; i <= 0; i++)
 {
     vetor[i] = rand() % 13;

//      printf("valor de i  eh %d \n",i);


      switch (vetor[i])
     {
        case 0:
             printf("%s gosta de %s\n",a,b);
             break;
        case 1:
            printf("%s gosta de %s\n",a,c);
            break;
        case 2:
            printf("%s gosta de %s\n",a,d);
            break;
        
        case 3:
            printf("%s gosta de %s\n",a,e);
            break;

         case 4:
            printf("%s gosta de %s\n",a,f);
            break;
        case 5:
            printf("%s gosta de %s\n",b,c);
            break;
        case 6:
            printf("%s gosta de %s\n",b,d);
            break;

        case 7:
            printf("%s gosta de %s\n",b,e);
            break;
       case 8:
            printf("%s gosta de %s\n",b,f);
            break;
        case 9:
            printf("%s gosta de %s\n",c,d);
            break;
        case 10:
            printf("%s gosta de %s\n",c,e);
            break;

        case 11:
            printf("%s gosta de %s\n",c,f);
            break;

        case 12:
            printf("%s gosta de %s\n",d,e);
            break;
        case 13:
            printf("%s gosta de %s\n",d,f);
            break;
        default:
            printf("entrou no switch mas nao entrou em nenhum dos casos\n");
            break;
     
     
     
     
     
     
     
     
     
     
     
     
     }

 }










  return 0;
}

