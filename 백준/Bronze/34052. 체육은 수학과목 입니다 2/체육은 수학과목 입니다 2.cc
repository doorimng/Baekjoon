#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int sum = 300 ;

    for ( int i = 0 ; i < 4 ; i ++ ) {
        int x ;
        cin >> x ;

        sum += x ;
    }

    if ( sum > 1800 ) cout << "No" ;
    else cout << "Yes" ;

    return 0 ;
}