#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n, m, k, ans = 0 ;
    cin >> n >> m >> k ;

    vector <ll> v (n+1, 0) ; 
    unordered_map <ll, ll> mp ;

    for ( int i = 0 ; i < n ; i ++ ) cin >> v[i] ;

    for ( int i = 0 ; i < n ; i ++ ) {
        ll temp = v[i] ^ k ;

        // 검사없이 바로 추가할 경우 0을 value로 가진 key 추가
        if ( mp.count(temp) ) ans += mp[temp] ;
        
        mp[v[i]] ++ ;
        
        if ( i >= m ) {
			if ( mp.count(v[i-m])) {
				mp[v[i-m]] -- ;
				
				if ( mp[v[i-m]] == 0 ) mp.erase(v[i-m]) ;
			}
        }
    }

    cout << ans ;

    return 0 ;
}