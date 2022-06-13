#include <stdio.h>
#include <stdlib.h>

typedef struct info {
    int num;
    struct info *prox;
} Info;

int main(void) {
    Info *info1, *info2;
    info1 = (Info *) malloc(sizeof(Info));
    info2 = (Info *) malloc(sizeof(Info));
    
    info1->num = 1;
    info2->num = 2;
    info1->prox = info2;
    
    printf("Valor 1 -> %d\n", info1->num);
    printf("Valor 2 -> %d\n", info1->prox->num);
    
    free(info2);
    free(info1);


    return 0;
}