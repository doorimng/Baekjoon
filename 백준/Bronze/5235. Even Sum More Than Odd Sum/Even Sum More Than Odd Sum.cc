#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int k ;
        cin >> k ;

        ll even = 0, odd = 0 ;

        for ( int j = 0 ; j < k ; j ++ ) {
            ll x ;
            cin >> x ;
    
            if ( x % 2 ) odd += x ;
            else even += x ;
        }

        if ( odd > even ) cout << "ODD\n" ;
        else if ( odd < even ) cout << "EVEN\n" ;
        else cout << "TIE\n" ;
    }

    return 0 ;
}