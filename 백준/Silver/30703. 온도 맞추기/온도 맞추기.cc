#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> a (n+1, 0), b (n+1, 0), c (n+1, 0) ;

    for ( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> b[i] ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> c[i] ;

    int Mx = 0 ;
    vector <int> v ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( abs(b[i] - a[i]) % c[i] ) {
            cout << -1 ;
            return 0 ;
        }
        else a[i] = abs(b[i] - a[i]) / c[i] ;

        Mx = max(Mx, a[i]) ;
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( Mx % 2 != a[i] % 2 ) {
            cout << -1 ;
            return 0 ;
        }
    }

    cout << Mx ;

    return 0 ;
}