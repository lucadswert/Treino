#include<stdio.h>

int numero;
int soma (int num);

int main(){
  printf("Digite um numero:");
   scanf("%d",&numero);
   printf("SOMA: %d\n", soma(numero));
   return 0;
}

int soma (int num){
  if(num == 0)
    return 0;
  else
    return num + soma(num - 1);
}