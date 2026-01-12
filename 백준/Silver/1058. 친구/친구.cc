#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int n ;
    cin >> n ;

    vector <vector <int>> v (n+1, vector <int> (n+1, 0)) ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= n ; j ++ ) {
            char c ;
            cin >> c ;

            if ( c == 'Y' )  v[i][j] = 1 ;
        }
    }

    int Mx = 0 ;
    vector <vector <int>> friends (n+1, vector <int> (n+2, 0)) ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= n ; j ++ ) {
            if ( v[i][j] ) {
                friends[i][j] = 1 ;
                for ( int k = 1 ; k <= n ; k ++ ) {
                    if ( v[j][k] && k != i ) {
                        friends[i][k] = 1 ;
                        friends[k][i] = 1 ;
                    }
                }
            }
        }
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= n ; j ++ ) {
            if ( friends[i][j] ) friends[i][n+1] ++ ;
        }
        Mx = max(Mx, friends[i][n+1]) ;
    }

    cout << Mx ;

    return 0 ;
}