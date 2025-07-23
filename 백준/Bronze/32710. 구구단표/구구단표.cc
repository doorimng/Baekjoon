#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    if ( n < 10 ) cout << 1 ;
    else {
        for ( int i = 2 ; i < 10 ; i ++ ) {
            if ( n % i == 0 && n / i < 10 ) {
                cout << 1 ;
                return 0 ;
            }
        }
        cout << 0 ;
    }

    return 0 ;
}