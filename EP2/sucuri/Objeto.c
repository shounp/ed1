#include <stdio.h>
#include <stdlib.h>

#include "Categorias.h"
#include "Objeto.h"

/**
 * @brief Cria um objeto sem tipo definido
 * 
 * @return Objeto* 
 */
Objeto *criaObjeto() {
    Objeto *obj = mallocSafe(sizeof(Objeto));
    obj->categoria  = INDEFINIDA;
    obj->valor.pStr = NULL;
    obj->proximo    = NULL;
    return obj;
}

/**
 * @brief Retona uma cópia independente do objeto
 * 
 * @param objeto Ponteiro para o objeto a ser copiado
 * @return Objeto* 
 */
Objeto *copiaObjeto(Objeto *objeto) {
    AVISO(Objeto.c: ainda não completei a função 'copiaObjeto');
    
    return NULL;
}

/**
 * @brief Faz a desalocação de memória apontada pelo objeto.
 * 
 * @param objeto Ponteiro para o objeto a ser desalocado
 */
void liberaObjeto(Objeto *objeto) {
    free(objeto);
}

/**
 * @brief Imprime as informações do objeto de acordo com o 'tipo' (Util.h) da impressão
 * desejada.
 * Se 'tipo' for:
 * - ITEM: será impresso o valor do campo 'valor.pStr'
 * - VALOR: será impresso o valor do campo 'valor' de acordo com a categoria do objeto
 * - POSFIXA: será impresso *apenas* o valor do campo 'valor' de acordo com a categoria do objeto. 
 * No caso de ser um operador, use a função getOperador(<categoria>) (Util.h) para imprimir o 
 * simbolo do operador
 * 
 * @param obj Ponteiro para o objeto a ser impresso
 * @param tipo Tipo da impressão (pode ser ITEM, VALOR ou POSFIXA) 
 */
void imprimeObjeto(Objeto *obj, int tipo) {
    if (tipo == ITEM) {
        printf("  \"%s\" (%s)\n", obj->valor.pStr, getNomeCategoria(obj->categoria));
    }
    else if(tipo == VALOR) {
        if (obj->categoria >= 0 && obj->categoria <= 8) {
            printf("  prec=%d (%s)\n", obj->valor.vInt, getNomeCategoria(obj->categoria));
        }
        else if (obj->categoria >= 9 && obj->categoria <= 10) {
            printf("  %s (%s)\n", obj->valor.pStr, getNomeCategoria(obj->categoria));
        }
        else if (obj->categoria == FLOAT) {
            /*VALOR FLOAT*/
            printf("  %lf (valor float)\n", obj->valor.vFloat);
        }
        else if (obj->categoria == INT) {
            /*VALOR INT*/
            printf("  %d (valor int)\n", obj->valor.vInt);
        }
    }
    else if (tipo == POSFIXA) {
        AVISO(Objeto.c: ainda não completei a função 'imprimeObjeto');
        //A função getOperador(<categoria>) pode ser útil :)
    }
}

/**
 * @brief Imprime o valor (inteiro ou real) do objeto. A função considera apenas as 
 * categorias INT e FLOAT.
 * 
 * @param obj Ponteiro para o objeto
 */
void imprimeValor(Objeto * obj) {
    if(obj->categoria == FLOAT)
        printf("%lf\n", obj->valor.vFloat);
    else if(obj->categoria == INT)
        printf("%d\n", obj->valor.vInt);
}