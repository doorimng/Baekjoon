#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n, m ;
    cin >> n >> m ;

    vector <ll> v (n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) cin >> v[i] ;

    sort(v.begin(), v.end()) ;

    ll low = 0, high = v[n-1], Mx = 0 ;

    while ( low < high ) {
        ll sum = 0, mid = (low + high) / 2 ;

        for ( int i = 0 ; i < n ; i ++ ) {
            if ( v[i] > mid ) sum += v[i] - mid ;
        }

        if ( sum >= m ) {
            Mx = mid ;
            low = mid + 1 ;
        }
        else {
            high = mid ;
        }
    }

    cout << Mx ;

    return 0 ;
}