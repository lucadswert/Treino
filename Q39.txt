#include<stdio.h>
int multIncremento(int a, int b);

int main()
{
    int n;
    int k;
    printf ("Multiplicar com Incrementos\n");
    printf ("Digite o 1° valor: ");
    scanf ("%d", &n);
    printf ("Digite o 2° valor: ");
    scanf ("%d", &k);
    printf ("Resultado: %d\n", multIncremento(n, k));
    return 0;
}

int multIncremento(int a, int b){
	if(a == 0 || b == 0) return 0;
	if(b == 1) return a;
	return a + multIncremento(a, b - 1);
}