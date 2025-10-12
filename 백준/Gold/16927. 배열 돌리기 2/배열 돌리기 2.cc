#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m, r, s = 0, nn, mm ;
vector <vector <ll>> v ;

int dx[4] = {0, 1, 0, -1} ;
int dy[4] = {1, 0, -1, 0} ;

void cycle(int y, int x) {

    ll dir = 0, temp = v[y][x] ;
    while ( dir < 4 ) {
        int yy = y + dy[dir] ;
        int xx = x + dx[dir] ;
    
        if ( yy < s || yy >= nn || xx < s || xx >= mm ) {
            dir ++ ;
            continue ;
        }

        ll cur = temp ;
        temp = v[yy][xx] ;
        v[yy][xx] = cur ;

        y = yy ; x = xx ;
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m >> r ;
    nn = n ; mm = m ;

    v.resize(n, vector <ll> (m, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    for ( int i = 0 ; i < min(n, m) / 2 ; i ++ ) {
        for ( int j = 0 ; j < r %  min((mm-s) * (nn-s), ((mm-s) * (nn-s) - (mm-s-2) * (nn-s-2))) ; j ++ ) {
            cycle(i, i) ;
        }
        s ++ ; nn -- ; mm -- ;
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cout << v[i][j] << " " ;
        }
        cout << "\n" ;
    }

    return 0 ;
}