#include<stdio.h>

void converte(int num);
int main(){
  int numero;
  printf("Digite um numero:");
  scanf("%d",&numero);
  printf("Resultado: \n");
  converte(numero);
  return 0;
}
void converte(int num){
  int n;
  if(num/2 != 0){
    n = num/2;
    converte(n);
    printf("%d",num%2);
  }
  else{
    printf("%d",num%2);
  }
}