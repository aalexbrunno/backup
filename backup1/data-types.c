// tipos de dados:
#include <stdio.h>
// #include <stdint.h>


int main(void)
{
    char x='g'; // %c ou %s (string)
    
    short int u=0;// %hi ou %hd
    int a=0;// %i ou %d
    long int b=0;// %li ou %ld
    long long int c=0;// %lli ou lld

    float d =0;// %f
    double e=0;// %lf
    long double f=0;// %Lf
    
    //sizeof(); => retorna o numeros de bytes de cada tipo de dado ocupa na memoria. 
    
    // --------------------------------------------//
    // imprimindo cada tipo de dado.
    printf("char %d bytes ou %d bits\n",sizeof(x),8*sizeof(x));
    printf("short %d bytes ou %d bits\n",sizeof(u),8*sizeof(u));
    printf("int %d bytes ou %d bits\n",sizeof(a),8*sizeof(a));
    printf("long int %d bytes ou %d bits\n",sizeof(b),8*sizeof(b));
    printf("long long int %d bytes ou %d bits\n",sizeof(c),8*sizeof(c));
    printf("float %d bytes ou %d bits\n",sizeof(d),8*sizeof(d));
    printf("double %d bytes ou %d bits\n",sizeof(e),8*sizeof(e));
    printf("long double %d bytes ou %d bits\n",sizeof(f),8*sizeof(f));
    // --------------------------------------------//
    
    // OBS: dependendo da arquitetura do computador e da configuração do compilador (gcc) o tamanho ocupado na memoria pode mudar*
}