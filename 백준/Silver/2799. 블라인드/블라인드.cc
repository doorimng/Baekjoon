#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int m, n ;
    cin >> m >> n ;

    vector <vector <char>> v (5000, vector <char> (5000, ' ')) ;

    for ( int i = 0 ; i < 5*m+1 ; i ++ ) {
        for ( int j = 0 ; j < 5*n+1 ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    vector <int> ans (5, 0) ;

    for ( int i = 1 ; i < 5*m+1 ; i += 5 ) {
        for ( int j = 1 ; j < 5*n+1 ; j += 5 ) {
            for ( int k = 0 ; k < 5 ; k ++ ) {
                if ( v[i+k][j] == '.' ) {
                    ans[k] ++ ;
                    break ;
                }

                if ( k == 4 ) ans[4] ++ ;
            }
        }
    }

    for ( int i = 0 ; i < 5 ; i ++ ) cout << ans[i] << " " ;

    return 0 ;
}