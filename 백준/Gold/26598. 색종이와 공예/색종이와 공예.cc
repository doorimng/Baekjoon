#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m ;
vector <vector <char>> v ;
vector <vector <int>> visited ;

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;
int MxY, MxX, MnY, MnX ;

queue <pii> q ;
void BFS() {
	while ( !q.empty() ) {

		int y = q.front().first ;
		int x = q.front().second ;
		q.pop() ;

		for ( int i = 0 ; i < 4 ; i ++ ) {
			int yy = y + dy[i] ;
			int xx = x + dx[i] ;
	
			if ( yy < 0 || xx < 0 || yy >= n || xx >= m || visited[yy][xx] ) continue ;
	
			if ( v[yy][xx] == v[y][x] ) {
				visited[yy][xx] = 1 ;
				q.push({yy, xx}) ;
				MxX = max(MxX, xx) ; MxY = max(MxY, yy) ;
				MnX = min(MnX, xx) ; MnY = min(MnY, yy) ;
			}
		}
	}
}

int is_square(int y, int x) {
	visited[y][x] = 1 ;
	MxY = y ; MxX = x ;
	MnY = y ; MnX = x ;
	q.push({y, x}) ;
	BFS() ;

	int check = true ;

	for ( int i = MnY ; i <= MxY ; i ++ ) {
		for ( int j = MnX ; j <= MxX ; j ++ ) {
			if ( v[i][j] != v[y][x] ) check = false ;
		}
	}

	return check ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

	cin >> n >> m ;

	v.resize(n+1, vector <char> (m+1, 0)) ;
	visited.resize(n+1, vector <int> (m+1, 0)) ;

	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			cin >> v[i][j] ;
		}
	}

	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			if ( !visited[i][j] ) {
				if ( !is_square(i, j) ) {
					cout << "BaboBabo" ;
					return 0 ;
				}
			}
		}
	}
	
	cout << "dd" ;
    return 0 ;
}