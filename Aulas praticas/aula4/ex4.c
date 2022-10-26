#include <stdio.h>
#include <stdlib.h>

#include "Racional.h"

int main(){
    int n,i,nel;
    Racional *x = inicializaRacional(1, 2);
    Racional *y = inicializaRacional(1, 4);
    Racional *z = NULL;

    printf("quantos termos:");
    scanf("%d",&n);
    nel=4;
    for(i=0;i<n-2;i++){
        z = somaRR(x ,y);
        imprimeRacional(z);
        setDen(x, getDen(z));
        setNum(x, getNum(z));
        setDem(y, nel*2);
    }

    return 0;
}