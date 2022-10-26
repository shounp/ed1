#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Objetos.h"
#include "Lista.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.7182818284590452354
#endif

int main() {

    /** Exercício 6 **/
    Lista *lista = criaLista();
    insereLista(lista, criaObjetoInteiro(10));
    insereLista(lista, criaObjetoReal(M_PI));
    insereLista(lista, criaObjetoString("UFES"));
    insereLista(lista, criaObjetoInteiro(25));
    insereLista(lista, criaObjetoString("CEUNES"));
    insereLista(lista, criaObjetoString("Sao Mateus"));
    insereLista(lista, criaObjetoReal(M_E));
    //String nome = malloc(100);
    //strcpy(nome, "GABRIEL");
    //insereLista(lista, criaObjetoString(nome));
    //free(nome);

    printf("Imprimindo a lista usando a função 'imprimeInformacaoObjeto'\n");
    printf("------------------------------------------------------------\n");
    imprimeLista(lista, imprimeInformacaoObjeto);
    //strcpy(nome, "MARTINS");
    //imprimeLista(lista, imprimeInformacaoObjeto);
    printf("------------------------------------------------------------\n");

    printf("\n\n");
    printf("Imprimindo a lista usando a função 'imprimeItemObjeto'\n");
    printf("------------------------------------------------------------\n");
    imprimeLista(lista, imprimeItemObjeto);
    printf("\n------------------------------------------------------------\n");
    liberaLista(lista);

    return 0;
}