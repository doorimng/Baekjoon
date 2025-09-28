#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <int> parent ;

int find(int x) {
    if ( parent[x] == -1 ) return x ;
    else {
        parent[x] = find(parent[x]) ;
        return parent[x] ;
    }
}


int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m, ans = 0 ;
    cin >> n >> m ;

    parent.resize(n+1, -1) ;

    int cnt = 0 ;
    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        cnt ++ ;

        if ( find(a) != find(b) ) {
            parent[find(a)] = find(b) ;
        }
        else {
            if ( !ans ) ans = cnt ;
        }
    }

    cout << ans ;
    
    return 0 ;
}