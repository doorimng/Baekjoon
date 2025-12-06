#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int level = 0 ;

// dp[level][left][right] ;
vector <vector <vector <int>>> dp ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    dp.resize(100001, vector <vector <int>> (5, vector <int> (5, INF))) ;
    // dp[0] = vector <vector <int>> (5, vector <int> (5, 0)) ;
    dp[0][0][0] = 0 ;

    while ( true ) {
        int x, temp ;
        cin >> x ;
        
        if ( x == 0 ) break ;    
        level ++ ;

        for ( int i = 0 ; i < 5 ; i ++ ) {
            for ( int j = 0 ; j < 5 ; j ++ ) {
                int l = i ;
                int r = j ;

                if ( dp[level-1][l][r] == INF ) continue ;

                if ( l == x || r == x ) {
                    dp[level][l][r] = min(dp[level][l][r], dp[level-1][l][r] + 1) ;
                }
                else {
                    // left 움직이기
                    if ( l == 0 ) temp = 2 ;
                    else if ( (l+2) % 4 == x % 4 ) temp = 4 ;
                    else temp = 3 ;
            
                    dp[level][x][r] = min(dp[level][x][r], dp[level-1][l][r] + temp) ;
            
                    if ( r == 0 ) temp = 2 ;
                    else if ( (r+2) % 4 == x % 4 ) temp = 4 ;
                    else temp = 3 ;
            
                    dp[level][l][x] = min(dp[level][l][x], dp[level-1][l][r] + temp) ;

                }
            }
        }
    }
    
    int ans = INF ;
    for ( int i = 0 ; i < 5 ; i ++ ) {
        for ( int j = 0 ; j < 5 ; j ++ ) {
            ans = min(ans, dp[level][i][j]) ;
        }
    }

    cout << ans ;

    return 0 ;
}