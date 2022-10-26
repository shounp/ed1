#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilha.h"
#include "Lista.h"
#include "Objetos.h"


bool verificaDelimitadores(char *);
char *posfixa(char *);

int main() {

    char s[10][100] = {
        {"A+B*C+D"},//A B C * + D +
        {"(A+B)*(C+D)"},//A B + C D + *
        {"A*B+C*D"},//A B * C D * +
        {"A+B+C+D"},//A B + C + D +
        {"(A+B)*C"},//A B + C *
        {"A+B"},//A B +
        {"A+B*C"},//A B C * +
        {"(A+B*(C+D))"},//A B C D + * +
        {"(A+(B/C)*D)*E"},//ABC/D*+E*
        {"A/C*D"}
    };
    char *resultado;
    for (int i = 0; i < 10; i++) {
        resultado = posfixa(s[i]);
        printf("'%s' ", resultado);
    }

    return 0;
}

char *posfixa(char* str) {
    char *resultado = malloc(100*sizeof(char));
    strcpy(resultado, '');
    Pilha *p = criaPilha();
    Lista *l = criaLista();
    for (int i = 0; s[i] != '\0'; ++i) {
        if(!(strcmp(s[i], "+")==0 || strcmp(s[i], "-")==0 || strcmp(s[i], "/")==0 || strcmp(s[i], "*")==0 || strcmp(s[i], "(")==0 || strcmp(s[i], ")")==0)){
            insereLista(l,criaObjetoString(s[i]));
        }
        else if(strcmp(s[i], "+")==0 || strcmp(s[i], "-")==0 || strcmp(s[i], "/")==0 || strcmp(s[i], "*")==0){
            if(strcmp(top(p), "*")==0 || strcmp(top(p), "/")==0){
                insereLista(l,criaObjetoString(top(p)))
                pop(p);
            }
            else
                push(p,s[i]);
        }
        else if(strcmp(s[i], ")")==0){
            insereLista(l,criaObjetoString(top(p)));
            pop(p);
        }
    }
    Objeto *aux = getPrimeiro(l);
    while(aux != NULL){
        strcpy(resultado,aux->item.STR);
    }

    liberaPilha(p);
    liberaLista(l);
    return resultado;

}