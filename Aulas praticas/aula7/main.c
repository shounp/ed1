#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

int main() {
    /** Exercício 1 **/
    /*printf("** Exercício 1 **\n");
    Lista *lista1 = criaLista();
    imprimeLista(lista1);
    insereInicioLista(lista1, 1);
    imprimeLista(lista1);
    insereInicioLista(lista1, 2);
    imprimeLista(lista1);
    insereInicioLista(lista1, 1);
    imprimeLista(lista1);
    printf("Tamanho da lista: %d\n\n", tamanhoLista(lista1));
    liberaLista(lista1);*/
    /*****************/

    /** Exercicio 2 **/
    /*printf("** Exercício 2 **\n");
    Lista *lista2 = criaLista();
    insereFimLista(lista2, 3);
    imprimeLista(lista2);
    insereFimLista(lista2, 4);
    imprimeLista(lista2);
    insereFimLista(lista2, 5);
    imprimeLista(lista2);
    printf("Tamanho da lista: %d\n\n", tamanhoLista(lista2));
    liberaLista(lista2);*/
    /*****************/

    /** Exercicio 3 **/
    /*printf("** Exercício 3 **\n");
    Lista *lista3 = criaLista();
    insereFimLista(lista3, 1);
    insereFimLista(lista3, 2);
    insereFimLista(lista3, 3);
    insereFimLista(lista3, 4);
    insereFimLista(lista3, 5);
    imprimeLista(lista3);
    No *n3 = procuraNoLista(lista3, ultimoNoLista(lista3));
    if (n3 != NULL) {
        printf("Nó encontrado. Valor: %d\n", n3->dado);
    }
    else {
        printf("Nó não encontrado\n");
    }
    n3 = malloc(sizeof(No));
    n3->dado = 5;
    n3->proximo = NULL;
    No *n32 = procuraNoLista(lista3, n3);
    if (n32 != NULL) {
        printf("Nó encontrado. Valor: %d\n", n32->dado);
    }
    else {
        printf("Nó não encontrado\n");
    }
    free(n3);
    liberaLista(lista3);*/
    /*****************/

    /** Exercicio 4 **/
    // printf("** Exercício 4 **\n");
    // Lista *lista4 = criaLista();
    // insereInicioLista(lista4, 1);
    // insereInicioLista(lista4, 2);
    // insereInicioLista(lista4, 3);
    // insereInicioLista(lista4, 3);
    // insereInicioLista(lista4, 3);
    // insereInicioLista(lista4, 4);
    // insereInicioLista(lista4, 5);
    // imprimeLista(lista4);
    // No *no4 = n_esimo(lista4, 1);
    // if (no4 /* no4 != NULL*/ ) {
    //     printf("Primeiro elemento: %d\n", no4->dado);
    // }
    // no4 = n_esimo(lista4, 4);
    // if (no4 /* no4 != NULL */) {
    //     printf("Quarto elemento: %d\n", no4->dado);
    // }
    // no4 = n_esimo(lista4, 10);
    // if (no4) {
    //     printf("Decimo elemento: %d\n\n", no4->dado);
    // }
    // else {
    //     printf("Não existe o decimo elemento\n\n");
    // }
    // liberaLista(lista4);
    /*****************/

    /** Exercicio 5 **/
    /*printf("** Exercício 5 **\n");
    Lista *lista5 = criaLista();
    imprimeLista(lista5);
    printf("Removendo os nós com valor 4 de uma lista vazia\n");
    removeElementoLista(lista5, 4);
    printf("Inserindo um nó com valor 4 na lista\n");
    insereInicioLista(lista5, 4);
    imprimeLista(lista5);
    printf("Removendo os nós com valor 4\n");
    removeElementoLista(lista5, 4);
    imprimeLista(lista5);
    liberaLista(lista5);

    lista5 = criaLista();
    insereInicioLista(lista5, 1);
    insereInicioLista(lista5, 2);
    insereInicioLista(lista5, 3);
    insereInicioLista(lista5, 3);
    insereInicioLista(lista5, 3);
    insereInicioLista(lista5, 4);
    insereInicioLista(lista5, 5);
    printf("\nRemoção de elementos de 'lista5'\n");
    imprimeLista(lista5);
    printf("Tamanho da lista: %d\n", tamanhoLista(lista5));
    printf("Removendo os nós com valor 357\n");
    removeElementoLista(lista5, 357);
    imprimeLista(lista5);
    printf("Removendo os nós com valor 3\n");
    removeElementoLista(lista5, 3);
    imprimeLista(lista5);
    printf("Removendo os nós com valor 5\n");
    removeElementoLista(lista5, 5);
    imprimeLista(lista5);
    printf("Removendo os nós com valor 1\n");
    removeElementoLista(lista5, 1);
    imprimeLista(lista5);
    printf("Tamanho da lista: %d\n", tamanhoLista(lista5));
    liberaLista(lista5);*/
    /*****************/

    /** Exercicio 6 **/
    /*printf("** Exercício 6 **\n");
    Lista *lista6 = criaLista();
    insereInicioLista(lista6, 1);
    insereInicioLista(lista6, 2);
    insereInicioLista(lista6, 3);
    insereInicioLista(lista6, 3);
    insereInicioLista(lista6, 4);
    insereInicioLista(lista6, 5);
    imprimeLista(lista6);
    removeNoLista(lista6, primeiroNoLista(lista6));
    imprimeLista(lista6);
    removeNoLista(lista6, ultimoNoLista(lista6));
    imprimeLista(lista6);
    removeNoLista(lista6, primeiroNoLista(lista6));
    imprimeLista(lista6);
    removeNoLista(lista6, primeiroNoLista(lista6));
    imprimeLista(lista6);
    removeNoLista(lista6, primeiroNoLista(lista6));
    imprimeLista(lista6);
    removeNoLista(lista6, primeiroNoLista(lista6));
    imprimeLista(lista6);
    removeNoLista(lista6, primeiroNoLista(lista6));
    imprimeLista(lista6);
    liberaLista(lista6);

    lista6 = criaLista();
    insereInicioLista(lista6, 1);
    insereInicioLista(lista6, 2);
    insereInicioLista(lista6, 3);
    insereInicioLista(lista6, 3);
    insereInicioLista(lista6, 4);
    insereInicioLista(lista6, 5);
    No *noEx6 = malloc(sizeof(No));
    noEx6->dado = 3;
    noEx6->proximo = NULL;
    removeNoLista(lista6, noEx6); // Nada deve ser feito, pois esse nó *não* faz parte da lista
    imprimeLista(lista6);
    free(noEx6);
    liberaLista(lista6);*/
    /*****************/


    /** Exercício 7 **/
    /*printf("** Exercício 7 **\n");
    Lista *lista7 = criaLista();
    insereMisteriosoLista(lista7, 1);
    insereMisteriosoLista(lista7, 5);
    insereMisteriosoLista(lista7, 0);
    insereMisteriosoLista(lista7, 10);
    insereMisteriosoLista(lista7, 2);
    insereMisteriosoLista(lista7, 7);
    insereMisteriosoLista(lista7, 3);
    imprimeLista(lista7);
    liberaLista(lista7);*/
    /*****************/

    /** Exercício 8 - Desafio **/
    printf("** Exercício 8 **\n");
    Lista *lista8 = criaLista();
    insereInicioLista(lista8, 1);
    insereInicioLista(lista8, 2);
    insereInicioLista(lista8, 3);
    insereInicioLista(lista8, 3);
    insereInicioLista(lista8, 4);
    insereInicioLista(lista8, 5);
    Lista *copia = copiaLista(lista8); //Deve ser *independente* da 'lista8'
    insereFimLista(copia, 123);
    insereFimLista(copia, 456);
    insereFimLista(copia, 789);
    printf("Lista original: ");
    imprimeLista(lista8);
    printf("Tamanho da lista original: %d\n", tamanhoLista(lista8));
    printf(" Lista copiada: ");
    imprimeLista(copia);
    printf("Tamanho da lista copiada: %d\n", tamanhoLista(copia));
    printf("Removendo alguns elementos da lista copiada...\n");
    removeNoLista(copia, primeiroNoLista(copia));
    removeNoLista(copia, ultimoNoLista(copia));
    imprimeLista(copia);
    printf("Tamanho da lista copiada: %d\n", tamanhoLista(copia));

    printf("\nLista original: ");
    imprimeLista(lista8);
    printf("Tamanho da lista original: %d\n", tamanhoLista(lista8));
    liberaLista(lista8);
    liberaLista(copia);
    /*****************/

    return 0;
}