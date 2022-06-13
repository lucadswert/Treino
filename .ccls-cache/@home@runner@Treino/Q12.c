#include<stdio.h>
int menorQnOrdenado(int n);

int main()
{
    int n;
    printf ("Valores em ordem crescente\n");
    printf ("Digite um numero: ");
    scanf("%d", &n);
    menorQnOrdenado(n);
    return 0;
}

int menorQnOrdenado(int n) {
	if(n == -1) {
		return 0;
	}
	1 + menorQnOrdenado(n - 1);
	printf("%d ", n);
  return n;
}
