#include <stdio.h>
#include <stdlib.h>

#include "VE1.h"

int main() {
    VE1  *v1 = criaVE1(5);
    adicionaVE1(v1, 1);
    adicionaVE1(v1, 2);
    adicionaVE1(v1, 3);
    adicionaVE1(v1, 4);
    adicionaVE1(v1, 5);
    if (!vazioVE1(v1))
        printf("1) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));
    adicionaVE1(v1, 6);
    if (!vazioVE1(v1))
        printf("2) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));

    removeVE1(v1);
    adicionaVE1(v1, 6);
    if (!vazioVE1(v1))
        printf("3) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));
    removeVE1(v1);
    if (!vazioVE1(v1))
        printf("4) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));
    removeVE1(v1);
    if (!vazioVE1(v1))
        printf("5) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));
    removeVE1(v1);
    if (!vazioVE1(v1))
        printf("6) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));
    removeVE1(v1);
    if (!vazioVE1(v1))
        printf("7) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));
    removeVE1(v1);
    if (!vazioVE1(v1))
        printf("8) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));
    else
        printf("Estrutura sem elementos\n");
    adicionaVE1(v1, 11);
    if (!vazioVE1(v1))
        printf("9) Elemento Retornado em VE1: %d\n", obtemElementoVE1(v1));

    liberaVE1(v1);
    return 0;
}