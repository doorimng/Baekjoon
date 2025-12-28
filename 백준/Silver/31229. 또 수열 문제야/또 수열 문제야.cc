#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX


int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v (100000, 0) ;

    v[0] = v[1] = 1 ;

    for ( int i = 2 ; i <= 1000 ; i ++ ) {
        if ( !v[i] ) {
            for ( int j = i+i ; j < 100000 ; j += i ) {
                v[j] = 1 ;
            }
        }
    }

    int i = 1 ;
    while ( i ++ ) {
        if ( n == 0 ) break ;

        if ( !v[i] ) {
            cout << i << " " ;
            n -- ;
        }
    }

    return 0 ;
}