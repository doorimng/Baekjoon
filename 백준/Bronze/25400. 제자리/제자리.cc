#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
	
	int n ;
	cin >> n ;

	int j = 1, cnt = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int x ;
		cin >> x ;

		if ( x == j ) {
			j ++ ;
			cnt ++ ;
		}   
	}

	cout << n - cnt ;

    return 0 ;
}