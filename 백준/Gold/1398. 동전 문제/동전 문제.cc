#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int t ;
    cin >> t ;
    
    ll D[3] = {25, 10, 1} ;
    vector <int> dp (100, INF) ;

    for ( int i = 0 ; i <= 99 ; i ++ ) {
        if ( i < 10 ) dp[i] = i ;
        else {
            for ( int x : D ) {
                if ( i-x >= 0 ) 
                    dp[i] = min(dp[i],  dp[i-x]+1) ;
            }
        }
    }

    while ( t -- ) {
        ll n, cnt = 0 ;
        cin >> n ;

        while ( n ) {
            ll temp = n%100 ;
            cnt += dp[temp] ;
            n /= 100 ;
        }

        cout << cnt << "\n" ;
    }

    return 0 ;
}