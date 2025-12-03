#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h> 
#include <string.h>

int n ;

int Cycle(int t) {
   int change[2] = {0} ;
   
   change[0] = t % 10 ;
   change[1] = (t/10 + t%10) % 10 ;

   return change[0] * 10 + change[1] ;
}

int main() {
   
   scanf("%d", &n) ;

   int t = n, cnt = 0 ;
   while ( 1 ) {
      t = Cycle(t) ;
      cnt ++ ;
      if ( t == n ) break ;
   }

   printf("%d", cnt) ;
   
   return 0;
} 