#include <stdio.h>
#include <stdlib.h>

int vFixo[10];
int *v;

*v = vFixo;

int main(){
int n;
printf("Qual o tamanho do array?\n");
scanf("%d", &n);

v[1] = (int) malloc(n * sizeof(int));

printf("%d\n", v[1]);
return 0;
}
