#include <stdio.h>
#include <stdlib.h>

#include "Racional.h"

int main(){
    Racional *x = inicializaRacional(5, 4);
    Racional *y = inicializaRacional(3, 2);
    Racional *z = NULL;
    imprimeRacional(x);
    imprimeRacional(y);
    imprimeRacional(z);

    setDen(x, 13);
    imprimeRacional(x);
    setDen(x, 0);
    imprimeRacional(x);

    z = multiplicaRR(x, y);
    imprimeRacional(z);
    multiplicaRI(z, 3);
    imprimeRacional(z);
    printf("\n");
    setDen(z, 13);

    imprimeRacional(z);


    liberaRacional(z);
    liberaRacional(x);
    liberaRacional(y);
}