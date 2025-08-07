#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
	
	ll k, n, s = 1, e = 1 ;
	cin >> k >> n ;

	vector <ll> v (k, 0) ;

	for ( int i = 0 ; i < k ; i ++ ) {
		cin >> v[i] ;
		e = max(e, v[i]) ;
	}	

	while ( true ) {
		if ( s >= e ) break ;

		ll mid = (s+e) / 2, cnt = 0 ;

		for ( int i = 0 ; i < k ; i ++ ) {
			cnt += v[i] / mid ;
		}

		if ( cnt >= n ) s = mid + 1 ; 
		else e = mid ;
	}

	int cnt = 0 ;
	for ( int i = 0 ; i < k ; i ++ ) {
		cnt += v[i] / e ;
	}
	if ( cnt >= n ) cout << e ;
	else cout << e-1 ;

    return 0 ;
}