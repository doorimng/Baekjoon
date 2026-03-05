#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int t ;
    cin >> t ;

    while ( t -- ) {
        ll n ;
        cin >> n ;

        if ( (n+1) % 3 == 0 
            || (n+4) % 6 == 0 
            || n % 9 == 0 ) cout << "TAK\n" ;
        else cout << "NIE\n" ;
    }

    return 0 ;
}