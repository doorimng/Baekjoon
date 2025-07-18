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
        int d, n, s, p ;
        cin >> d >> n >> s >> p ;

        s *= n ;
        p *= n ;

        p += d ;


        if ( s < p ) cout << "do not parallelize\n" ;
        else if ( s == p ) cout << "does not matter\n" ;
        else cout << "parallelize\n" ;
    }

    return 0 ;
}