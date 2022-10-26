#include <stdio.h>
#include <stdlib.h>

#include "VE2.h"

int main() {
    VE2  *v2 = criaVE2(5);
    adicionaVE2(v2, 1);
    adicionaVE2(v2, 2);
    adicionaVE2(v2, 3);
    adicionaVE2(v2, 4);
    adicionaVE2(v2, 5);
    if (!vazioVE2(v2))
        printf("1) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));
    adicionaVE2(v2, 6);
    if (!vazioVE2(v2))
        printf("2) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));

    removeVE2(v2);
    adicionaVE2(v2, 6);
    if (!vazioVE2(v2))
        printf("3) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));
    removeVE2(v2);
    if (!vazioVE2(v2))
        printf("4) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));
    removeVE2(v2);
    if (!vazioVE2(v2))
        printf("5) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));
    removeVE2(v2);
    if (!vazioVE2(v2))
        printf("6) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));
    removeVE2(v2);
    if (!vazioVE2(v2))
        printf("7) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));
    removeVE2(v2);
    if (!vazioVE2(v2))
        printf("8) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));
    else
        printf("Estrutura sem elementos\n");
    adicionaVE2(v2, 11);
    if (!vazioVE2(v2))
        printf("9) Elemento Retornado em VE2: %d\n", obtemElementoVE2(v2));

    printf("\n\n");
    VE2 *v = criaVE2(5);
    /*Note que o código insere e remove elementos na estrutura*/
    /*A estrutura tem capacidade = 5 e são inseridos 10 valores*/
    /*Se sua implementação está correta, isso não deve ser problema*/
    for(int i = 0; i < 10; i++){
        printf("Iteracao %d:\n", i);
        printf(" - Inserindo o valor: %d\n", i);
        adicionaVE2(v, i);
        printf(" -        #Elementos: %d\n", tamanhoVE2(v));
        printf(" - Primeiro Elemento: %d\n\n", obtemElementoVE2(v));
        removeVE2(v);
    }

    printf("#Elementos: %d\n", tamanhoVE2(v)); /* Deve ser 0 */

    liberaVE2(v2);
    liberaVE2(v);
    return 0;
}