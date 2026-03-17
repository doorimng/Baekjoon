#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m, t, cnt = 1 ;
int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

vector <vector <double>> v ;
vector <vector <int>> visited ;

queue <pii> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
            if ( !visited[yy][xx] && v[yy][xx] >= t ) {
                visited[yy][xx] = visited[y][x] ;
                q.push({yy, xx}) ;
            }
        }
    }
}

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    cin >> n >> m ;

    v.resize(n+1, vector <double> (m+1, 0)) ;
    visited.resize(n+1, vector <int> (m+1, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            double r, g, b ;
            cin >> r >> g >> b ;

            v[i][j] = (r+g+b)/3 ;
        }
    }

    cin >> t ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            if ( v[i][j] >= t && !visited[i][j] ) {
                visited[i][j] = cnt ++ ;
                q.push({i, j}) ;
                BFS() ;
            }
        }
    }

    cout << cnt-1 ;

    return 0 ;
}