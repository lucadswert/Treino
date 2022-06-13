#include<stdio.h>
int somaDigitos(int n);

int main()
{
    int n;
    printf ("Somar valores dos digitos\n");
    printf ("Digite um numero: ");
    scanf("%d", &n);
    printf ("Resultado: %d\n", somaDigitos(n));
    return 0;
}

int somaDigitos(int n){
	if(n < 10) return n % 10;
	return somaDigitos(n / 10) + n % 10;
}