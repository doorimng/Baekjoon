#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX


int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll k, n ;
    cin >> k >> n ;

    ll temp = 1 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        ll x ;
        cin >> x ;

        temp = temp * x / __gcd(temp, x) ;
    }

    ll ans = temp - k ;
    if ( ans <= 0 ) ans += temp ;

    cout << ans ;

    return 0 ;
}