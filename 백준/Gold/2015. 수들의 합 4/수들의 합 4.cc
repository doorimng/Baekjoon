#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n, k, cnt = 0 ;
    cin >> n >> k ;

    map <ll, ll> mp ;
    vector <ll> v (n+1, 0) ;

    mp[0] ++ ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        ll x ;
        cin >> x ;

        v[i] = v[i-1] + x ;

        cnt += mp[v[i] - k] ;
        mp[v[i]] ++ ;
    }

    cout << cnt ;

    return 0 ;
}