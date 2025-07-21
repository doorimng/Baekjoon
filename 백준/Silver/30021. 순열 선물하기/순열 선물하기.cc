#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    if ( n == 1 ) cout << "YES\n1" ;
    else if ( n == 2 ) cout << "NO" ;
    else if ( n == 3 ) cout << "YES\n1 3 2" ;
    else {
        cout << "YES\n4 2 3 1 " ;
        for ( int i = 5 ; i <= n ; i ++ ) cout << i << " " ;
    }

    return 0 ;
}