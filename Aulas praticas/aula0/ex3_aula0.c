# include <stdio.h>

     int main () {
     int x = 10 ;
     int *p1 , *p2 ;
     p1 = &x ;
     p2 = p1 ;
     printf (" End. x = %p\n", &x ) ;
     printf (" End. p1 = %p\n", &p1 ) ;
     printf (" End. p2 = %p\n", &p2 ) ;
     printf (" End. apontado por p1 = %p\n", p1 ) ;
     printf (" End. apontado por p2 = %p\n", p2 ) ;
     printf (" Valor do end. apontado por p1 = %d\n", *p1 ) ;
     printf (" Valor do end. apontado por p2 = %d\n", *p2 ) ;
     return 0 ;
     }
