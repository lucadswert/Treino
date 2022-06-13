#include<stdio.h>
int crescentePares(int n);

int main()
{
    int n;
    printf ("Valores em ordem crescente\n");
    printf ("Digite um numero: ");
    scanf("%d", &n);
    crescentePares(n);
    return 0;
}

int crescentePares(int n) {
	if(n < 0) {
		return 0;
	}
	2 + crescentePares(n - 2);
	printf("%d ", n);
  return n;
}

