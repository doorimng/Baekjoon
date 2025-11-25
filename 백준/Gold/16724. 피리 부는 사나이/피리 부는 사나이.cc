#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m ;
vector <vector <char>> v ;
vector <vector <pii>> parent ;

pii unionFind(pii info) {
    int y = info.first ;
    int x = info.second ;

    if ( parent[y][x] == make_pair(-1, -1) ) return {y, x} ;
    else {
        parent[y][x] = unionFind(parent[y][x]) ;
        return parent[y][x] ;
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m ;
    v.resize(n, vector <char> (m, 0)) ;
    parent.resize(n, vector <pii> (m, {-1, -1})) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            int yy = i, xx = j ;
            if ( v[i][j] == 'R' ) xx ++ ;
            if ( v[i][j] == 'L' ) xx -- ;
            if ( v[i][j] == 'D' ) yy ++ ;
            if ( v[i][j] == 'U' ) yy -- ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;

            if ( unionFind({i, j}) != unionFind({yy, xx}) ) {
                parent[unionFind({i, j}).first][unionFind({i, j}).second] = unionFind({yy, xx}) ;
            }
        }
    }

    int cnt = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            if ( parent[i][j] == make_pair(-1, -1) ) cnt ++ ;
        }
    }

    cout << cnt ;

    return 0 ;
}