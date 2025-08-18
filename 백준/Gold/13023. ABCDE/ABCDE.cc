#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m, Mx = -1 ;
vector <vector <int>> v ;
vector <int> visited ;

void DFS(int n, int cnt) {
    visited[n] = 1 ;
    for ( int x : v[n] ) {
        if ( visited[x] ) continue ;
        if ( cnt > 4 ) return ;

        visited[x] = 1 ;
        DFS(x, cnt+1) ;
    }
    visited[n] = 0 ;
    Mx = max(Mx, cnt) ;
    return ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m ;
    v.resize(n+1, vector <int> (0)) ;
    visited.resize(n+1, 0) ;

    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        v[a].push_back(b) ;
        v[b].push_back(a) ;
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        DFS(i, 0) ;
        
        if ( Mx >= 4 ) {
            cout << 1 ;
            return 0 ;
        }
    }

	cout << 0 ;
    return 0 ;
}