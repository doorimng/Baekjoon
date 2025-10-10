#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m, cnt = 0 ;
    cin >> n >> m ;

    vector <vector <char>> v (n, vector <char> (m, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    int dy[4] = {-1, 1, 0, 0} ;
    int dx[4] = {0, 0, 1, -1} ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            if ( v[i][j] == 'X' ) {
                for ( int k = 0 ; k < 4 ; k ++ ) {
                    int y = i + dy[k] ;
                    int x = j + dx[k] ;

                    if ( y < 0 || y >= n || x < 0 || x >= m ) continue ;
                    if ( v[y][x] != 'Y' ) continue ;

                    cnt ++ ;
                }
            }
        }
    }

    cout <<  cnt ;

    return 0 ;
}