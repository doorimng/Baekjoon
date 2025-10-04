#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m, cnt = 1 ;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1} ;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1} ;

vector <vector <int>> v (100, vector <int> (100, 0)) ;
vector <vector <int>> visited (100, vector <int> (100, 0)) ;

queue <pii> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;

        for ( int i = 0 ; i < 8 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || xx < 0 || yy >= n || xx >= m ) continue ;
            if ( visited[yy][xx] || v[yy][xx] != v[y][x] ) continue ;

            cnt ++ ;
            visited[yy][xx] = 1 ;
            q.push({yy, xx}) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        cin >> n >> m ;

        v.clear() ;
        v.resize(n, vector <int> (m, 0)) ;
        visited.clear() ;
        visited.resize(n, vector <int> (m, 0)) ;

        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                cin >> v[i][j] ;
            }
        }

        set <int> st ;
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( !visited[i][j] ) {
                    if ( v[i][j] == -1 ) {
                        visited[i][j] = 1 ;
                        continue ;
                    }
                    q.push({i, j}) ;
                    visited[i][j] = 1 ;
                    cnt = 1 ;
                    BFS() ;

                    if ( cnt > 1 ) st.insert(v[i][j]) ;
                }
            }
        }
        cout << st.size() << "\n" ;
    }

    return 0 ;
}