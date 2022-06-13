#include<stdio.h>
int decrescentePares(int n);

int main()
{
    int n;
    printf ("Valores em ordem crescente\n");
    printf ("Digite um numero: ");
    scanf("%d", &n);
    decrescentePares(n);
    return 0;
}

int decrescentePares(int n) {
	if(n == 0) {
		printf("%d ", 0);
		return 0;
	}
	if(n % 2 == 0) {
		printf("%d ", n);
	}
	decrescentePares(n - 1);
  return n;
}