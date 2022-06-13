#include<stdio.h>

int pot(int k, int n)
{
    if(n==0) return 1;
    if(n==1) return k;
    return k *(pot(k, n-1));
}

int main()
{
    int n;
    int k;
    printf ("Digite o valor da Base: ");
    scanf ("%d", &k);
    printf ("Digite o valor do Expoente: ");
    scanf ("%d", &n);
    printf ("Resultado: %d\n", pot(k, n));
    return 0;
}