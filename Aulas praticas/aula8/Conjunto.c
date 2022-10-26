
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */

#include "Conjunto.h"


typedef struct conjunto {
    No *inicio;
    No *fim;
    int n;
} Conjunto;

Conjunto *criaConjuntoVazio(){
    /*
     * Cria um conjunto vazio e retorna o ponteiro desse conjunto
     */
    Conjunto *c = malloc(sizeof(Conjunto));
    c->inicio = c->fim = NULL;
    c->n = 0;
    return c;
}

Conjunto *criaConjuntoValores(int num_args, ...){
    /*
     * Cria um conjunto a partir de uma lista de valores passados como parâmetro.
     * Leia mais sobre função com número variável de argumentos
     * nesse link: http://www.cplusplus.com/reference/cstdarg/
     * ou https://en.cppreference.com/w/c/variadic
    */
    Conjunto *c = criaConjuntoVazio();
    int valor;
    va_list ap;
    va_start(ap, num_args);
    for(int i = 0; i < num_args; i++) {
        valor = va_arg(ap, int);
        insere(c, valor);
    }
    va_end(ap);

    return c;
}

Conjunto *criaConjuntoArray(int *v, int n){
    /*
     * Cria um conjunto a partir dos elementos de um vetor.
     */
    Conjunto *c = criaConjuntoVazio();
    for(int i = 0; i < n; i++)
        insere(c, v[i]);
    return c;
}

void libera(Conjunto *c){
    /*
     * Faz a liberação de toda memória utilizada
     */
    No *atual = c->inicio;
    while (atual != NULL) {
        No *t = atual->proximo;
        free(atual);
        atual = t;
    }
    free(c);
    c = NULL;
}

void insere(Conjunto *c, int v){
    /*
     * Insere um elemento no *fim* do conjunto (lista).
     * Por ser um conjunto, note que primeiro devemos verificar se o valor
     * já está no conjunto. Se estiver, ele não deve ser incluido novamente.
     */

    if (pertence(c, v)) return;

    No *no = malloc(sizeof(No));
    no->valor = v;
    no->proximo = NULL;
    no->anterior = c->fim;
    if (c->inicio == NULL) {
        c->inicio = c->fim = no;
    }
    else {
        c->fim->proximo = no;
        c->fim = no;
    }
    c->fim = no;
    c->n++;
}

void removeElemento(Conjunto *c, int valor) {
    /*
     * Remove o elemento 'valor' do conjunto, caso ele exista.
     * Lembre-se de manter os ponteiros do conjunto consistentes.
     */

    No *p = busca(c, valor);
    if(p == NULL)
        return;
    if(p == c->inicio)
        c->inicio = p->proximo;
    else
        p->anterior->proximo = p->proximo;
    if(p == c->fim)
        c->fim = p->anterior;
    else
        p->proximo->anterior = p->anterior;
    c->n--;
    free(p);
}

No *busca(Conjunto *c, int valor){
    /*
     * Porcura no conjunto o elemento 'valor'. Caso ele exista,
     * um ponteiro para o nó é retornado. Caso contrário, é retornado NULL
     */
    No* atual = c->inicio;
    while(atual != NULL){
        if(atual->valor == valor)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

bool pertence(Conjunto *c, int valor) {
    /*
     * Verifica se existe um nó com 'valor' no conjunto. Caso exista,
     * a função retorna true. Caso contrário, ela retorna false.
     */
    return busca(c, valor) != NULL;
}

void imprime(Conjunto *c) {
    /*
     * Função para imprimir os elementos do conjunto.
     */
    No *atual = c->inicio;
    int t = tamanho(c);
    if (t == 0){
        printf("{}\n");
        return;
    }
    else if(t == 1) {
        printf("{%d}\n", atual->valor);
        return;
    }
    printf("{");
    while(atual != c->fim) {
        printf("%d, ", atual->valor);
        atual = atual->proximo;
    }
    printf("%d}\n", atual->valor);
}

void imprimeReverso(Conjunto *c) {
    /*
     * Função para imprimir os elementos do conjunto de forma inversa.
     */
    No *atual = c->fim;
    int t = tamanho(c);
    if (t == 0){
        printf("{}\n");
        return;
    }
    else if(t == 1) {
        printf("{%d}\n", atual->valor);
        return;
    }
    printf("{");
    while(atual != c->inicio) {
        printf("%d, ", atual->valor);
        atual = atual->anterior;
    }
    printf("%d}\n", atual->valor);
}

Conjunto *copia(Conjunto *A) {
    /*
     * Retorna uma cópia do conjunto 'A'.
     * Use as função do TAD Conjunto para simplificar a implementação.
     */
    Conjunto *c = criaConjuntoVazio();
    if(A == NULL){
        return NULL;
    }
    No *aux = A->inicio;
    while(aux != NULL){
        insere(c,aux->valor);
        aux = aux->proximo;
    }
    return c;
}

Conjunto *uniao(Conjunto *A, Conjunto *B){
    /*
     * Cria um *novo* conjunto contendo a união dos conjuntos 'A' e 'B'.
     * Exemplo: {2, 3} U {1, 2, 3, 4} = {1, 2, 3, 4}
     *
     * Dica: crie uma cópia do conjunto 'A' e percorra os elementos de 'B',
     *       inserindo-os no novo conjunto.
     */

    Conjunto *c = copia(A);
    No *aux = B->inicio;

    while(aux != NULL){
        if (pertence(A, aux->valor) != true ){
            insere(c,aux->valor);
            aux = aux->proximo;
        }
        else
            aux = aux->proximo;
    }
    return c;
}

Conjunto *intersecao(Conjunto *A, Conjunto *B){
    /*
     * Cria um *novo* conjunto contendo a interseção dos conjuntos 'A' e 'B'.
     * Exemplo: {1, 2, 4, 8} ∩ {2, 3, 5, 7} = {2}
     *
     * Dica: insira no novo conjunto apenas os elementos de 'A' que pertencem a 'B'.
     */
     if(A == NULL || B == NULL)
        return NULL;

    Conjunto *c = criaConjuntoVazio();
    No *aux = A->inicio;

    while(aux != NULL){
        if(pertence(B,aux->valor) == true){
            insere(c,aux->valor);
            aux = aux->proximo;
        }
        else
           aux = aux->proximo;
    }
    return c;

}

Conjunto *diferenca(Conjunto *A, Conjunto *B){
    /*
     * Cria um *novo* conjunto contendo a diferença dos conjuntos 'A' e 'B'.
     * Exemplo: {1, 2, 4, 8} − {2, 3, 5, 7} = {1, 4, 8}
     *
     * Dica: insira no novo conjunto apenas os elementos de 'A' que não pertencem a 'B'.
     */
    Conjunto *c = criaConjuntoVazio();

    if(A == NULL || B == NULL)
        return NULL;

    No *aux = A->inicio;

    while(aux != NULL){
        if(pertence(B,aux->valor) != true){
            insere(c,aux->valor);
            aux = aux->proximo;
        }
        else
           aux = aux->proximo;
    }

    return c;
}

bool iguais(Conjunto *A, Conjunto *B){
    /*
     * A função deve retornar true se os dois conjuntos forem iguais, ou seja,
     * se contiverem os mesmos elementos (independente da ordem).
     * Exemplos: iguais({1, 2, 4}, {2, 1, 4}) -> true
     *           iguais({1, 2, 3}, {2, 3}) -> false
     *           iguais({1, 2, 3}, {}) -> false
     *           iguais({}, {1}) -> false
     *           iguais({}, {}) -> true
     *
     * Dicas: 1) Se o tamanho de A e B forem diferente, precisamos fazer alguma verificação?
     *        2) Percorra o conjunto A se algum de seus elementos não estiver em B retorne false.
     */
    if(A->n != B->n)
        return false;

    No *aux = A->inicio;

    while(aux != NULL){
        if(pertence(B,aux->valor) != true){
            return false;
        }
        else
           aux = aux->proximo;
    }

    return true;
}

int contaSe(Conjunto *c, bool (*compara)(int)) {
    /*
     * Função de alta ordem que conta a quantidade de elementos
     * que satisfazem a função 'compara' (passada como parâmetro),
     * ou seja, se compara(no->valor) == true
     *
     * Dica: para cada elemento do conjunto verifique se compara(no->valor) == true
     */
    No *aux = c->inicio;
    int i = 0;
    while(aux != NULL){
        if(compara(aux->valor)){
            i++;
            aux = aux->proximo;
        }
        else
            aux = aux->proximo;
    }
    return i;
}

void transforma(Conjunto *c, int (*funcao)(int)) {
    /*
     * Função de alta ordem que
     *
     * Dica: para cada elemento do conjunto aplique a 'funcao' no campo 'valor'
     */
    No *aux = c->inicio;
    while(aux != NULL){
        aux->valor = funcao(aux->valor);
        aux = aux->proximo;
    }

}

int tamanho(Conjunto *c) {
    return c->n;
}

bool vazio(Conjunto *c) {
    return c->n == 0;
}