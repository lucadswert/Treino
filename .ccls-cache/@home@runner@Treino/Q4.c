#include<stdio.h>
#define TAM 10
int soma (int v[], int tam);

int main(){
  int vet[TAM] = {1,2,3,4,5,6,7,8,9,10};
  printf("SOMA: %d\n", soma(vet, 10));
  return 0;
}

int soma (int v[], int tam){
  if(tam == 0)
    return 0;
  else
    return v[tam-1] + soma(v, tam - 1);
}