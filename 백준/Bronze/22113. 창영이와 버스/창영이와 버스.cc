#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
	
	int n, m ;
	cin >> n >> m ;
	
	int bus[101] = {0, } ;
	for ( int i = 0 ; i < m ; i ++ ) {
		cin >> bus[i] ;
	}

	vector <vector <int>> cost (n+1, vector <int> (n+1, 0)) ;

	for ( int i = 1 ; i <= n ; i ++ ) {
		for ( int j = 1 ; j <= n ; j ++ ) {	
			cin >> cost[i][j] ;
		}
	}

	int sum = 0 ;
	for ( int i = 1 ; i < n ; i ++ ) {
		sum += cost[bus[i-1]][bus[i]] ;
	}

	cout << sum ;

    return 0 ;
}