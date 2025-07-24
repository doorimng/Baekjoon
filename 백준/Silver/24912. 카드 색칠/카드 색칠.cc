#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, check = true ;
    cin >> n ;

    vector <int> v (n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;

        if ( i > 0 && v[i] == v[i-1] && v[i] != 0 ) check = false ; 
    }

    if ( !check ) {
        cout << -1 ; 
        return 0 ;
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        if ( v[i] == 0 ) {
            for ( int j = 1 ; j <= 3 ; j ++ ) {
                if ( i-1 >= 0 && v[i-1] == j ) continue ;
                if ( i+1 < n && v[i+1] == j ) continue ;

                v[i] = j ;
                break ;
            }
            if ( v[i] == 0 ) {
                cout << -1 ;
                return 0 ;
            }
        }
    }

    for ( int i = 0 ; i < n ; i ++ ) cout << v[i] << " " ;

    return 0 ;
}