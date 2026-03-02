#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int Mx = 123456*2 ;

    vector <int> v (Mx+1, 1) ;
    v[0] = v[1] = 0 ;

    for ( int i = 2 ; i <= sqrt(Mx) ; i ++ ) {
        if ( v[i] ) {
            for ( int j = i+i ; j <= Mx ; j += i ) {
                v[j] = 0 ;
            }
        }
    }

    for ( int i = 2 ; i <= Mx ; i ++ ) {
        v[i] += v[i-1] ;
    }

    while ( true ) {
        int n ;
        cin >> n ;

        if ( n == 0 ) break ;

        cout << v[2*n] - v[n] << "\n" ;
    }

    return 0 ;
}