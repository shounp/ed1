#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Objetos.h"

Objeto *criaObjetoInteiro(int valor) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = INT;
    obj->item.vInt = valor;
    obj->proximo = NULL;
    return obj;
}

Objeto *criaObjetoReal(double valor) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = FLOAT;
    obj->item.vFloat = valor;
    obj->proximo = NULL;
    return obj;
}

Objeto *criaObjetoString(char *palavra) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = STR;
    obj->item.vString = palavra;
    obj->proximo = NULL;
    return obj;
}

void liberaObjeto(Objeto *obj) {
    if(obj == NULL)
        return;
    else {
        free(obj);
        obj = NULL;
    }
}

void imprimeInformacaoObjeto(Objeto *obj) {
    if (obj == NULL)
        return;
    if(obj->tipo == INT) {
        printf("Inteiro com valor: %d\n", obj->item.vInt);
    }
    else if (obj->tipo == FLOAT) {
        printf("Real com valor: %lf\n", obj->item.vFloat);
    }
    else if (obj->tipo == STR) {
        printf("String com valor: %s\n", obj->item.vString);
    }
    else {
        printf("Tipo não reconhecido\n");
    }
}

void imprimeItemObjeto(Objeto *obj) {
    if (obj == NULL)
        return;
    if(obj->tipo == INT) {
        printf("%d ", obj->item.vInt);
    }
    else if (obj->tipo == FLOAT) {
        printf("%lf ", obj->item.vFloat);
    }
    else if (obj->tipo == STR) {
        printf("%s ", obj->item.vString);
    }
    else {
        printf("Tipo não reconhecido ");
    }
}