#include <bits/stdc++.h>

// 내리막길 이거 DFS문제임

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1} ;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1} ;

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    while ( true ) {
        int n, m ;
        cin >> n >> m ;

        if ( n == 0 && m == 0 ) break ;

        vector <vector <char>> v (n+1, vector <char> (m+1, ' ')) ;

        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                cin >> v[i][j] ;
            }
        }

        for ( int y = 0 ; y < n ; y ++ ) {
            for ( int x = 0 ; x < m ; x ++ ) {
                if ( v[y][x] == '*' ) cout << v[y][x] ;
                else {
                    int cnt = 0 ;
                    for ( int i = 0 ; i < 8 ; i ++ ) {
                        int yy = y + dy[i] ;
                        int xx = x + dx[i] ;
    
                        if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
                        if ( v[yy][xx] == '*' ) cnt ++ ;
                    }
                    cout << cnt ;
                }
            }
            cout << "\n" ;
        }
    }


    return 0 ;
}