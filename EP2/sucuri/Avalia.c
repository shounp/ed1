#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Avalia.h"
#include "Categorias.h"
#include "Pilha.h"
#include "Util.h"

/**
 * @brief Faz a avaliação da expressão em notação pós-fixa e retorna o resultado da expressão.
 * A sua função deve examinar cada objeto da fila 'posFixa' e:
 * - Se o objeto for um operando (FLOAT ou INT), empilhar o objeto;
 * - Se o objeto contém um operador, então:
 *   - Desempilhar um ou dois números da pilha, dependendo do tipo do operador;
 *   - Calcular o valor da operação correspondente; e
 *   - Empilhar o valor calculado.
 * Ao final (quando a fila estiver vazia), retorne o objeto (ou uma cópia) do topo da pilha.
 * 
 * @param posFixa Fila com os objeto em notação pos-fixa
 * @return Objeto* 
 */
Objeto *avalia(Fila *posFixa) {
    AVISO(Avalia.c: ainda não completei a função 'avalia');

    

    return NULL;
}
