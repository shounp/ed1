#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Objetos.h"

Objeto *criaObjetoInteiro(int valor) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = INT;
    obj->item = malloc(sizeof(int));
    *(int *)obj->item = valor;
    obj->proximo = NULL;
    return obj;
}

Objeto *criaObjetoReal(double valor) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = FLOAT;
    obj->item = malloc(sizeof(double));
    *(double *)obj->item = valor;
    obj->proximo = NULL;
    return obj;
}

Objeto *criaObjetoString(char *palavra) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = STR;
    //obj->item = palavra;

    obj->item = malloc((strlen(palavra)+1)*sizeof(char));
    strcpy((char *)obj->item, palavra);

    obj->proximo = NULL;
    return obj;
}

void liberaObjeto(Objeto *obj) {
    if(obj == NULL) return;
    //if(obj->tipo == INT || obj->tipo == FLOAT)
    free(obj->item);
    free(obj);
    obj = NULL;

}

void imprimeInformacaoObjeto(Objeto *obj) {
    if (obj == NULL)
        return;

    if(obj->tipo == INT) {
        printf("Inteiro com valor: %d\n", *(int *)(obj->item));
    }
    else if (obj->tipo == FLOAT) {
        printf("Real com valor: %lf\n", *(double *)(obj->item));
    }
    else if (obj->tipo == STR) {
        //printf("String com valor: %s\n", (String)(obj->item));
        printf("String com valor: %s\n", (char *)(obj->item));
    }
    else {
        printf("Tipo não reconhecido\n");
    }
}

void imprimeItemObjeto(Objeto *obj) {
    if (obj == NULL)
        return;

    if(obj->tipo == INT) {
        printf("%d ", *(int *)(obj->item));
    }
    else if (obj->tipo == FLOAT) {
        printf("%lf ", *(double *)(obj->item));
    }
    else if (obj->tipo == STR) {
        //printf("%s ", (String)(obj->item));
        printf("%s ", (char *)(obj->item));
    }
    else {
        printf("Tipo não reconhecido ");
    }
}