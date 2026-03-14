#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int n ;
    cin >> n ;

    ll ans = 0, sum = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        ll x ;
        cin >> x ;

        if ( sum + x < 0 ) {
            ans = max(ans, abs(sum+x)) ;
        }

        sum += x ;
    }

    cout << ans ;
    
    return 0 ;
}