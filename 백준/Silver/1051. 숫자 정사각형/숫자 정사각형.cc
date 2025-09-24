#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    vector <vector <char>> v (n, vector <char> (m, 0));

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    int Mx = 0 ;
    for ( int k = 1 ; k <= min(n, m) ; k ++ ) {
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( i+k > n ) continue ;
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( j+k > m ) continue ;

                int temp = v[i][j] ;
                if ( v[i+k-1][j] == temp && v[i][j+k-1] == temp && v[i+k-1][j+k-1] == temp ) Mx = max(Mx, k) ;
            }
        }
    }

    cout << Mx * Mx ;

    return 0 ;
}