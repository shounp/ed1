# include <stdio.h>
    int main () {
    int * p ;
    int c = 15 ;
    p = & c;
    printf (" Antes da alteracao de ’p ’\n") ;
    printf (" Valor de ’c ’: %d\n", c ) ;
    printf (" Valor de ’*p ’: %d\n", * p ) ;
    *p = *p + 1 ; // Altera o conteudo para onde o ponteiro ’p’ aponta
    printf (" Depois da alteracao de ’p ’\n") ;
    printf (" Valor de ’c ’: %d\n", c ) ;
    printf (" Valor de ’*p ’: %d\n", * p ) ;
    return 0 ;
    }