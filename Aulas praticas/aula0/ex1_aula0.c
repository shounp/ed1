# include <stdio.h>

 int main () {
 int * m ;
 int count = 100 ;
 m = & count ;
 printf (" Endereco de ’count ’: %p\n", & count ) ;
 printf (" Endereco de ’m ’: %p\n", & m ) ;
 printf (" Endereco de apontado por ’m ’: %p\n", m ) ;
    return 0 ;
}
