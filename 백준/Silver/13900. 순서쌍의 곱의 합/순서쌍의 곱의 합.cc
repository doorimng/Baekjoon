#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n, Mx = 0 ;
    cin >> n ;

    vector <ll> v (10005, 0) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        ll x ;
        cin >> x ;

        Mx = max(Mx, x) ;

        v[x] ++ ;
    }

    Mx ++ ;

    ll sum = 0 ;
    for ( int i = 0 ; i < Mx; i ++ ) {
        if ( v[i] > 1 ) sum += i * i * (v[i] * (v[i]-1) / 2) ;
        for ( int j = i+1 ; j <= Mx ; j ++ ) {
            sum += i * j * v[i] * v[j] ;
        }
    }

    cout << sum ;

    return 0 ;
}