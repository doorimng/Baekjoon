#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
	
	int n, is_press = 0, cnt = 0 ;
	cin >> n ;

	for ( int i = 0 ; i < n ; i ++ ) {
		double x ;
		cin >> x ;

		if ( x == 0 ) continue ;

		cnt += floor(x) ;
		if ( !is_press && (int)(x*2) % 2 == 1 ) cnt ++ ;
		
		is_press = 1 ;
	}

	cout << cnt ;

    return 0 ;
}