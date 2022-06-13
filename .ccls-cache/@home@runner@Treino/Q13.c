#include<stdio.h>
int menorQnDecrescente(int n);

int main()
{
    int n;
    printf ("Valores em ordem crescente\n");
    printf ("Digite um numero: ");
    scanf("%d", &n);
    menorQnDecrescente(n);
    return 0;
}

int menorQnDecrescente(int n) {
	if(n == -1) {
		return 0;
	}
	printf("%d ", n);
	return menorQnDecrescente(n - 1);
}

