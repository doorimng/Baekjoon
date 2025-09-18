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

    ll low = 0, high = INF, ans = 0 ;

    while ( low <= high ) {
        ll mid = (low + high) / 2 ;

        ll sum = 0, cnt = 1 ;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( v[i] > mid ) {
                cnt = m + 10 ;
                break ;
            }

            if ( sum + v[i] > mid ) {
                sum = 0 ;
                cnt ++ ;
            }
            
            sum += v[i] ;
        }

        if ( cnt > m ) {
            low = mid + 1 ;
        }
        else {
            ans = mid ;
            high = mid - 1 ;
        }
    }

    cout << ans ;

    return 0 ;
}