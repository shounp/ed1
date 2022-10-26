#include <stdio.h>
#include <stdlib.h>

#include "FilaPrioridade.h"

int main() {
    FilaPrioridade  *fila = criaFilaPrioridade();
    insere(fila, 0);
    insere(fila, 1);
    insere(fila, 3);
    insere(fila, 5);
    insere(fila, 7);
    insere(fila, 2);
    
    printf("Elemento de maior prioridade: %d\n", primeiro(fila));
    
    printf("Removendo o elemento de maior prioridade...\n");
    removeMax(fila);
    printf("Novo elemento de maior prioridade: %d\n", primeiro(fila));

    printf("Removendo o elemento de maior prioridade...\n");
    removeMax(fila);
    printf("Novo elemento de maior prioridade: %d\n", primeiro(fila));

    printf("Removendo o elemento de maior prioridade...\n");
    removeMax(fila);
    printf("Novo elemento de maior prioridade: %d\n", primeiro(fila));

    liberaFilaPrioridade(fila);
    return 0;
}