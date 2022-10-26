Pilha *p#include <stdio.h>
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

bool analisaExpressao(Lista *);
double valorexpressao(Lista *);
int main() {

    /** Exercício 4 **/
    // Lista *lista = criaLista();
    // insereLista(lista, criaObjetoInteiro(10));
    // insereLista(lista, criaObjetoReal(M_PI));
    // insereLista(lista, criaObjetoString("UFES"));
    // insereLista(lista, criaObjetoInteiro(25));
    // insereLista(lista, criaObjetoString("CEUNES"));
    // insereLista(lista, criaObjetoString("Sao Mateus"));
    // insereLista(lista, criaObjetoReal(M_E));

    // printf("Imprimindo a lista usando a função 'imprimeInformacaoObjeto'\n");
    // printf("------------------------------------------------------------\n");
    // imprimeLista(lista, imprimeInformacaoObjeto);
    // printf("------------------------------------------------------------\n");

    // printf("\n\n");
    // printf("Imprimindo a lista usando a função 'imprimeItemObjeto'\n");
    // printf("------------------------------------------------------------\n");
    // imprimeLista(lista, imprimeItemObjeto);
    // printf("\n------------------------------------------------------------\n");
    // liberaLista(lista);

    /** Exercício 5 **/
    double resultado;
    Lista *expressaoMat = criaLista();
    insereLista(expressaoMat, criaObjetoInteiro(10));
    insereLista(expressaoMat, criaObjetoString("+"));
    insereLista(expressaoMat, criaObjetoInteiro(15));
    imprimeLista(expressaoMat, imprimeItemObjeto);
    if(analisaExpressao(expressaoMat)){
        printf("\nExpressao correta!\n\n");
        resultado = valorexpressao(expressaoMat);
        printf("\nA soma é: %lf \n\n",resultado);
    }
    else
        printf("\nExpressao incorreta!\n\n");
    liberaLista(expressaoMat);

    expressaoMat = criaLista();
    insereLista(expressaoMat, criaObjetoInteiro(10));
    insereLista(expressaoMat, criaObjetoString("+"));
    insereLista(expressaoMat, criaObjetoInteiro(15));
    insereLista(expressaoMat, criaObjetoString("-"));
    imprimeLista(expressaoMat, imprimeItemObjeto);
    if (analisaExpressao(expressaoMat)){
        printf("\nExpressao correta!\n\n");
        resultado = valorexpressao(expressaoMat);
        printf("\nA soma é: %lf \n\n",resultado);
    }
    else
        printf("\nExpressao incorreta!\n\n");
    liberaLista(expressaoMat);


    expressaoMat = criaLista();
    insereLista(expressaoMat, criaObjetoInteiro(10));
    insereLista(expressaoMat, criaObjetoInteiro(15));
    imprimeLista(expressaoMat, imprimeItemObjeto);
    if (analisaExpressao(expressaoMat)){
        printf("\nExpressao correta!\n\n");
        resultado = valorexpressao(expressaoMat);
        printf("\nA soma é: %lf \n\n",resultado);
    }
    else
        printf("\nExpressao incorreta!\n\n");
    liberaLista(expressaoMat);

    expressaoMat = criaLista();
    insereLista(expressaoMat, criaObjetoString("+"));
    imprimeLista(expressaoMat, imprimeItemObjeto);
    if (analisaExpressao(expressaoMat)){
        printf("\nExpressao correta!\n\n");
        resultado = valorexpressao(expressaoMat);
        printf("\nA soma é: %lf \n\n",resultado);
    }
    else
        printf("\nExpressao incorreta!\n\n");
    liberaLista(expressaoMat);

    expressaoMat = criaLista();
    insereLista(expressaoMat, criaObjetoInteiro(10));
    imprimeLista(expressaoMat, imprimeItemObjeto);
    if (analisaExpressao(expressaoMat)){
        printf("\nExpressao correta!\n\n");
        resultado = valorexpressao(expressaoMat);
        printf("\nA soma é: %lf \n\n",resultado);
    }
    else
        printf("\nExpressao incorreta!\n\n");
    liberaLista(expressaoMat);

    expressaoMat = criaLista();
    insereLista(expressaoMat, criaObjetoString("-"));
    insereLista(expressaoMat, criaObjetoInteiro(10));
    imprimeLista(expressaoMat, imprimeItemObjeto);
    if (analisaExpressao(expressaoMat)){
        printf("\nExpressao correta!\n\n");
        resultado = valorexpressao(expressaoMat);
        printf("\nA soma é: %lf \n\n",resultado);
    }
    else
        printf("\nExpressao incorreta!\n\n");
    liberaLista(expressaoMat);

    expressaoMat = criaLista();
    insereLista(expressaoMat, criaObjetoString("-"));
    insereLista(expressaoMat, criaObjetoReal(3.5));
    insereLista(expressaoMat, criaObjetoString("-"));
    insereLista(expressaoMat, criaObjetoReal(1.3));
    imprimeLista(expressaoMat, imprimeItemObjeto);
    if (analisaExpressao(expressaoMat)){
        printf("\nExpressao correta!\n\n");
        resultado = valorexpressao(expressaoMat);
        printf("\nA soma é: %lf \n\n",resultado);
    }
    else
        printf("\nExpressao incorreta!\n\n");
    liberaLista(expressaoMat);

    return 0;
}

bool analisaExpressao(Lista *expressao){
    if(expressao == NULL)
        return false;

    int num=0, simb=0;
    Objeto *aux = getPrimeiro(expressao);
    while(aux){
        if(aux->proximo == NULL){
            if(simb == 0 && num == 0){
                if(aux->tipo == STR)
                    return false;
                else
                    return true;
            }
            else if(num == 1) {
                return false;
            }
            else{
                return true;
            }
        }
        else if(aux->proximo != NULL){
            if((aux->tipo == INT || aux->tipo == FLOAT) && simb == 0 && num == 0){
                num++;
                aux = aux->proximo;
            }
            else if(aux->tipo == STR && simb == 0 && num == 0){
                simb++;
                aux = aux->proximo;
            }
            else if(simb == 1){
                if(aux->tipo == STR){
                    return false;
                }
                else{
                    simb--;
                    aux = aux->proximo;
                }
            }
            else if(num == 1){
                if(aux->tipo == INT || aux->tipo == FLOAT){
                    return false;
                }
                else{
                    num--;
                    aux = aux->proximo;
                }
            }
        }
        else{
            return false;
        }
    }
    return true;
}

double valorexpressao(Lista *expressao){
    double num = 0, valor;
    Objeto *aux = getPrimeiro(expressao);
    while(aux){
        if(aux->tipo == STR){
            if(strcmp(aux->item.vString,"-") == 0){
                if(aux->proximo->tipo == INT){
                    valor = aux->proximo->item.vInt;
                }
                else{
                    valor = aux->proximo->item.vFloat;
                }
                num = num - valor;
                aux = aux->proximo;
            }
            else{
                if(aux->proximo->tipo == INT){
                    valor = aux->proximo->item.vInt;
                }
                else{
                    valor = aux->proximo->item.vFloat;
                }
                num = num + valor;
                aux = aux->proximo;
            }
        }
        else{
            if(aux->tipo == INT){
                    valor = aux->item.vInt;
            }
            else{
                valor = aux->item.vFloat;
            }
            num = valor;
        }
        aux = aux->proximo;
    }
    return num;
}