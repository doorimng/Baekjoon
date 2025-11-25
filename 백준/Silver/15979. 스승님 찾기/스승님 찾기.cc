#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int m, n ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> m >> n ;

    if ( n == 0 && m == 0 ) cout << 0 ;
    else if ( m == 0 || n == 0 ) {
        if ( abs(n+m) > 1 ) cout << 2 ;
        else cout << 1 ;
    }
    else {
        if ( m % 2 == 0 && n % 2 == 0 ) cout << 2 ;
        else if ( abs(m) == abs(n) ) {
            if ( abs(m) == 1 ) cout << 1 ;
            else cout << 2 ;
        }
        else cout << 1 ;
    }

    return 0 ;
}