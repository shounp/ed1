#include <stdio.h>
#include <stdlib.h>

/*typedef enum {
    false,
    true
} bool;*/

#include "Pilha.h"


bool verificaDelimitadores(char *);

int main() {

    char s[10][100] = {
        {"( ( ) [ ( ) ] )"},
        {"[(1+2)*(3+4)]^2"},
        {"( [ ) ]"},
        {"[(1+2)*(3+4)]*10)"},
        {"a = a + (c + d) * (e - f);"},
        {"g[10] = h[i[9]] + (j + k)*1"},
        {"while (m < (n[8] + o) ) { p = (7 + 2) * 3; }"},
        {"a = a + (c + d) * (e - f));"},
        {"g[10] = h[i[9]] + (j + k*1;"},
        {"while (m < (n[8) + o] ) { p = (7 + 2) * 3; }"}
    };
    for (int i = 0; i < 10; i++) {
        printf("'%s' ", s[i]);
        if (verificaDelimitadores(s[i]))
            printf("está correta\n");
        else
            printf("está incorreta\n");
    }

    return 0;
}

/**
 * @brief A função retorna true se a string contiver uma sequência
 * balanceada de delimitadores e false, caso contrário. Caracteres
 * diferentes de '(', ')', '[', ']', '{' e '}' devem ser ignorados.
 *
 * @param s string com a sequência a ser testada.
 * @return true ou false
 */
bool verificaDelimitadores(char * str) {
    Pilha * p = criaPilha();
    for (int i = 0; str[i] != '\0'; ++i) {
        char c;
        switch (str[i]) {
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
                push(p, str[i]);
                break;
            case ']':
                if (pilhaVazia(p)) {
                    liberaPilha(p);
                    return false;
                }
                c = top(p);
                pop(p);
                if (c != '[') {
                    liberaPilha(p);
                    return false;
                }
                break;
            case '[':
                push(p, str[i]);
                break;
            case '}':
                if (pilhaVazia(p)) {
                    liberaPilha(p);
                    return false;
                }
                c = top(p);
                pop(p);
                if (c != '{') {
                    liberaPilha(p);
                    return false;
                }
                break;
            case '{':
                push(p, str[i]);
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