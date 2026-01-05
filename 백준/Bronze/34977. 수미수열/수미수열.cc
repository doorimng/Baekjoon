#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v (n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;
    }

    for ( int k = 1 ; k <= n/2 ; k ++ ) {
        int check = 1 ;
        for ( int i = 0 ; i < k ; i ++ ) {
            if ( v[i] != v[n-k+i] ) {
                check = 0 ;
                break ;
            }
        }

        if ( check ) {
            cout << "yes" ;
            return 0 ;
        }
    }

    cout << "no" ;
    return 0 ;
}