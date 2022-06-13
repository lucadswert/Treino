#include<stdio.h>
int somaIncremento(int a, int b);

int main()
{
    int n;
    int k;
    printf ("Soma com Incrementos\n");
    printf ("Digite o 1° valor: ");
    scanf ("%d", &n);
    printf ("Digite o 2° valor: ");
    scanf ("%d", &k);
    printf ("Resultado: %d\n", somaIncremento(n, k));
    return 0;
}

int somaIncremento(int a, int b){
	if(a == 0) return b;
	if(b == 0) return a;
	return 1 + somaIncremento(a, b - 1);
}