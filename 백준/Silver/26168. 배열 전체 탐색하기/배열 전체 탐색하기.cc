#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <ll> v ;
ll q(ll n) {
    ll low = -1, high = v.size() ;

    while ( low + 1 < high ) {
        ll mid = (low + high) / 2 ;

        if ( n > v[mid] ) low = mid ;
        else high = mid ;
    }
    
    return high ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    for ( int i = 0 ; i < n ; i ++ ) {
        ll x ;
        cin >> x ;

        v.push_back(x) ;
    }

    sort(v.begin(), v.end()) ;

    while ( m -- ) {
        int cmd ;
        cin >> cmd ;

        if ( cmd == 3 ) {
            ll i, j ;
            cin >> i >> j ;

            ll b = q(j+1), a = q(i) ;
            cout << b - a ;
        }
        else {
            ll k ;
            cin >> k ;

            if ( cmd == 1 ) cout << n - q(k) ;
            else cout << n - q(k+1) ;
        }
        cout << "\n" ;
    }

    return 0 ;
}