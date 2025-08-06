#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
	
	int n, m ;
	cin >> n >> m ;

	int mina = INF, minb = INF ;

	for ( int i = 0 ; i < m ; i ++ ) {
		int a, b ;
		cin >> a >> b ;

		mina = min(a, mina) ;
		minb = min(b, minb) ;
	}

	int ans = 0 ;
	while ( n > 0 ) {
		if ( n >= 6 ) {
			if ( minb * 6 < mina ) ans += minb*6 ;
			else ans += mina ;
			n -= 6 ;
		}
		else {
			if ( minb * n < mina ) ans += minb * n ;
			else ans += mina ;
			n = 0 ;
		}
	}

	cout << ans ;

    return 0 ;
}