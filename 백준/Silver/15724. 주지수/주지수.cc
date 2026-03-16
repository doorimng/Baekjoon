#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int n, m ;
    cin >> n >> m ;

    vector <vector <ll>> v (n+1, vector <ll> (m+1, 0)) ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            ll x ;
            cin >> x ;

            v[i][j] = v[i-1][j] + v[i][j-1] + x - v[i-1][j-1] ;
        }
    }

    int k ;
    cin >> k ;

    for ( int i = 0 ; i < k ; i ++ ) {
        int x1, y1, x2, y2 ;
        cin >> x1 >> y1 >> x2 >> y2 ;

        cout << v[x2][y2] - v[x1-1][y2] - v[x2][y1-1] + v[x1-1][y1-1] << "\n" ;
    }

    return 0 ;
}