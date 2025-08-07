#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <int>> v ;
vector <vector <vector <int>>> dp ;

// 대각선 이동
int dx[3] = {1, 1, 0} ;
int dy[3] = {0, 1, 1} ;

int n ;

// ㅡ : 0, ㅣ : 1, / : 2 
void f(int y, int x, int head) {
	if ( head != 1 ) {
		if ( x+1 < n && !v[y][x+1] ) {
			dp[0][y][x+1] = dp[0][y][x] + dp[2][y][x] ;
			f(y, x+1, 0) ;
		}
	}

	if ( head != 0 ) {
		if ( y+1 < n && !v[y+1][x] ) {
			dp[1][y+1][x] = dp[1][y][x] + dp[2][y][x] ;
			f(y+1, x, 1) ;
		} 
	}

	int check = true ;
	for ( int i = 0 ; i < 3 ; i ++ ) {
		int yy = y + dy[i] ;
		int xx = x + dx[i] ;

		if ( yy >= n || xx >= n || v[yy][xx] ) check = false ;
	}
	if ( check ) {
		dp[2][y+1][x+1] = dp[0][y][x] + dp[1][y][x] + dp[2][y][x] ;
		f(y+1, x+1, 2) ;
	}

	return ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
	
	cin >> n ;

	v.resize(n+1, vector <int> (n+1, 0)) ;
	dp.resize(3, vector <vector <int>> (n+1, vector <int> (n+1, 0))) ;
	
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < n ; j ++ ) {
			cin >> v[i][j] ;
		}
	}
	
	dp[0][0][0] = dp[0][0][1] = 1 ;
	f(0, 1, 0) ;

	// for ( int k = 0 ; k < 3 ; k ++ ) {
	// 	cout << "======================\n" ;
	// 	for ( int i = 0 ; i < n ; i ++ ) {
	// 		for  ( int j = 0 ; j < n ; j ++ ) {
	// 			cout << dp[k][i][j] << " " ;
	// 		}
	// 		cout << "\n" ;
	// 	}
	// }

	cout << dp[0][n-1][n-1] + dp[1][n-1][n-1] + dp[2][n-1][n-1] ;

    return 0 ;
}