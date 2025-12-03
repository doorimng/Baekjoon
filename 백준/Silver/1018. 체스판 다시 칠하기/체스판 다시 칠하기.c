#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h> 
#include <string.h>

char white_first[8][8] = {
   {"WBWBWBWB"}, 
   {"BWBWBWBW"},
   {"WBWBWBWB"}, 
   {"BWBWBWBW"}, 
   {"WBWBWBWB"}, 
   {"BWBWBWBW"}, 
   {"WBWBWBWB"}, 
   {"BWBWBWBW"} } ;

char black_first[8][8] = {
   {"BWBWBWBW"}, 
   {"WBWBWBWB"}, 
   {"BWBWBWBW"}, 
   {"WBWBWBWB"}, 
   {"BWBWBWBW"}, 
   {"WBWBWBWB"}, 
   {"BWBWBWBW"}, 
   {"WBWBWBWB"} } ;

char board[51][51] = {} ;

int Min(int a, int b) {
   return (a < b) ? a : b ; 
}

int Colored(int y, int x) {
   int cnt_w = 0, cnt_b = 0 ;
   for ( int i = y ; i < y + 8 ; i ++ ) {
      for ( int j = x ; j < x + 8 ; j ++ ) {
         if ( board[i][j] != white_first[i-y][j-x] ) cnt_w ++ ;
         if ( board[i][j] != black_first[i-y][j-x] ) cnt_b ++ ;
      }
   }

   return Min(cnt_w, cnt_b) ;
}

int main() {

   int n, m ;
   scanf("%d %d", &n, &m) ;
   
   for ( int i = 0 ; i < n ; i ++ ) {
      scanf("%s", board[i]) ;
   }

   int answer = 100000000 ;

   for ( int i = 0 ; i <= n-8 ; i ++ ) {
      for ( int j = 0 ; j <= m-8 ; j ++ ) {
         answer = Min(Colored(i, j), answer) ;
      }
   }

   printf("%d", answer) ;

   return 0;
} 