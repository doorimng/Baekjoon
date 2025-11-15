#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    int n, ans = INF ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        if ( b >= a ) ans = min(ans, b) ;
    }

    if ( ans == INF ) cout << -1 ;
    else cout << ans ;

    return 0 ;
}