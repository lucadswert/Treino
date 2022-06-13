#include<stdio.h>

int numero;
int aux;
int inverteNumero(int n);
int main()
{
   printf("Digite um numero:");
   scanf("%d",&numero);
   inverteNumero(numero);
   return 0;
}
int inverteNumero(int n)
{
    if(n==0)
      return n;
     else
    {
     printf("%d", n % 10);
     n=n / 10;
     return inverteNumero(n);
    }
return 0;
 }