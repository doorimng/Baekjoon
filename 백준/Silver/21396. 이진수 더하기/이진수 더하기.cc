#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll t ;
    cin >> t ;

    while ( t -- ) {
        ll n, x, cnt = 0 ;
        cin >> n >> x ;
        map <ll, ll> mp ;

        for ( int i = 0 ; i < n ; i ++ ) {
            ll x ;
            cin >> x ;

            mp[x] ++ ;
        }

        if ( x == 0 ) {
            for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
                if ( it->second >= 2 ) {
                    ll a = it->second ;
                    cnt += a * (a-1) ;
                }
            }
        }
        else {
            for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
                ll a = it->first ;
                cnt += mp[a^x] * mp[a] ;
            }
        }

        cout << cnt / 2 << "\n" ;
    }

    return 0 ;
}