#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

/**
 * @brief A função retorna true se a string contiver uma sequência
 * balanceada de parênteses e false, caso contrário. Caracteres
 * diferentes de '(' e ')' são ignorados.
 *
 * @param s string com a sequência de parêntes a ser testada.
 * @return true ou false
 */
bool bemFormada (char s[]) {
    Pilha * p = criaPilha();
    for (int i = 0; s[i] != '\0'; ++i) {
        char c;
        switch (s[i]) {
            case ')':
                if (pilhaVazia(p)) {
                    liberaPilha(p);
                    return false;
                }
                c = top(p);
                pop(p);
                if (c != '(') {
                    liberaPilha(p);
                    return false;
                }
                break;
            case '(':
                push(p, s[i]);
                break;
        }
    }
    if (pilhaVazia(p)) {
        liberaPilha(p);
        return true; //string bem-formada
    }
    else {
        liberaPilha(p);
        return false; //string mal-formada
   }
}

int main(){
    char s[10][100] = {
        {"()()"},
        {"(())"},
        {"(()()()())"},
        {"(((())))"},
        {"(()((())()))"},
        {"(()))"},
        {")("},
        {"((((((())"},
        {"()))"},
        {"(()()(()"}
    };
    for (int i = 0; i < 10; i++) {
        printf("'%s' ", s[i]);
        if (bemFormada(s[i]))
            printf("está correta\n");
        else
            printf("está incorreta\n");
    }

    return 0;
}