#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

ll fastPow(ll a, ll b) {
    ll ans = 1 ;
    while ( b ) {
        if ( b % 2 ) ans *= a ;
        a *= a ;
        b /= 2 ;
    }
    return ans ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll t, MONEY = 5000000 ;
    cin >> t ;

    while ( t -- ) {
        ll money = 0, year = 1 ;

        vector <int> v ;
        while ( true ) {
            ll x ;
            cin >> x ;

            if ( x == 0 ) break ;

            v.push_back(x) ;
        }

        sort(v.begin(), v.end(), greater<>()) ;

        for ( int i = 0 ; i < v.size() ; i ++ ) {
            money += 2 * fastPow(v[i], year++) ;   
        }

        if ( money > MONEY ) cout << "Too expensive\n" ;
        else cout << money << "\n" ;
    }

    return 0 ;
}