#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int isPrime(int n) {
    for ( int i = 2 ; i < n ; i ++ ) {
        if ( n % i == 0 ) return 0 ;
    }
    return 1 ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    vector <int> v (50000001, 0) ;

    v[0] = v[1] = 1 ;
    for ( int i = 2 ; i <= sqrt(50000000) ; i ++ ) {
        if ( !v[i] ) {
            for ( int j = i + i ; j <= 50000000 ; j += i ) {
                v[j] = 1 ;
            }
        }
    }

    while ( true ) {
        int n ;
        cin >> n ;

        if ( cin.eof() ) break ;

        if ( n < 8 ) cout << "Impossible.\n" ;
        else {
            if ( n % 2 ) {
                cout << "2 3 " ;
                n -= 5 ;
            }
            else {
                cout << "2 2 " ;
                n -= 4 ;
            }

            for ( int i = 2 ; i < n ; i ++ ) {
                if ( !v[i] ) {
                    if ( isPrime(n-i) ) {
                        cout << i << " " << n-i << "\n" ;
                        break ;
                    }
                }
            }
        }
    }

    return 0 ;
}