#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m, cnt = INF ;
vector <vector <char>> v ;
vector <vector <int>> visited_s ;
vector <vector <int>> visited_j ;

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

queue <pii> qt ;
void BFS_S() {
    while ( !qt.empty() ) {
        int y = qt.front().first ;
        int x = qt.front().second ;
        qt.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
            if ( visited_s[yy][xx] != -1 || v[yy][xx] == '#' ) continue ;

            visited_s[yy][xx] = visited_s[y][x] + 1 ;
            qt.push({yy, xx}) ;
        }
    }
}

queue <pii> qj ;
void BFS_J() {
    while ( !qj.empty() ) {
        int y = qj.front().first ;
        int x = qj.front().second ;
        qj.pop() ;
        
        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;
            
            if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
            if ( visited_j[yy][xx] != -1 || v[yy][xx] == '#' ) continue ;

            visited_j[yy][xx] = visited_j[y][x] + 2 ;

            if ( v[yy][xx] == 'S' ) {
                cnt = min(cnt, visited_j[yy][xx]) ;
                continue ;
            }
            if ( v[yy][xx] == 'T' ) {
                if ( visited_s[yy][xx] == -1 ) continue ;
                cnt = min(cnt, visited_s[yy][xx] + visited_j[yy][xx]) ;
            }
            
            qj.push({yy, xx}) ;
        }
    }
}

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    cin >> n >> m ;
    v.resize(n+1, vector <char> (m+1, ' ')) ;
    visited_s.resize(n+1, vector <int> (m+1, -1)) ;
    visited_j.resize(n+1, vector <int> (m+1, -1)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> v[i][j] ;

            if ( v[i][j] == 'S' ) {
                visited_s[i][j] = 0 ;
                qt.push({i, j}) ;
            }

            if ( v[i][j] == 'J' ) {
                visited_j[i][j] = 0 ;
                qj.push({i, j}) ;
            }
        }
    }

    BFS_S() ;
    BFS_J() ;

    if ( cnt == INF ) cout << -1 ;
    else cout << cnt ;

    return 0 ;
}

