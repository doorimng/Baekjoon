#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

	int n ;
	cin >> n ;

	vector <ll> dp (1000001, 0) ;

	dp[1] = 1 ;
	dp[2] = 2 ;

	for ( int i = 3 ; i <= n ; i ++ ) {
		dp[i] = (dp[i-1] + dp[i-2]) % 15746 ;
	}

	cout << dp[n] ;
	
    return 0 ;
}