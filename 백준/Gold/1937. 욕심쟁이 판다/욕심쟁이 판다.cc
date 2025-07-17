#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <int>> node ;
vector <vector <int>> check ;

int n ;
int dy[4] = {1, -1, 0, 0} ;
int dx[4] = {0, 0, 1, -1} ;

int DFS(int y, int x) {
    if ( check[y][x] ) return check[y][x] ;

    for ( int i = 0 ; i < 4 ; i ++ ) {
        int yy = y + dy[i] ;
        int xx = x + dx[i] ;

        if ( yy < 0 || yy >= n || xx < 0 || xx >= n ) continue ;
        if ( node[y][x] >= node[yy][xx] ) continue ;

        check[y][x] = max(check[y][x], DFS(yy, xx) + 1) ;
    }

    return check[y][x] ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;

    node.resize(n+1, vector <int> (n, 0)) ;
    check.resize(n+1, vector <int> (n, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> node[i][j] ;
        }
    }

    int Mx = 0 ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            Mx = max(Mx, DFS(i, j)) ;
        }
    }

    cout << Mx+1 ;

    return 0 ;
}