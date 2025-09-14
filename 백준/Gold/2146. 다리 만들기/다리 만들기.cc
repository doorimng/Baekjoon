#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

int n, ans = INF ;
vector <vector <int>> v ;
vector <vector <int>> land ;

queue <pii> q ;
void BFS(int k) {
    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= n ) continue ;
            if ( v[yy][xx] == 0 || land[yy][xx] ) continue ;

            land[yy][xx] = k ;
            q.push({yy, xx}) ;
        }
    }
}

void find_land() {
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( v[i][j] == 1 && !land[i][j] ) {
                land[i][j] = i*n+j+1 ;
                q.push({i, j}) ;
                BFS(i*n+j+1) ;
            }
        }
    }
}

queue <pii> test ;
vector <vector <int>> visited ;

void bridgeBFS(int temp) {
    while ( !test.empty() ) {
        int y = test.front().first ;
        int x = test.front().second ;
        test.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= n ) continue ;
            if ( visited[yy][xx] || land[yy][xx] == temp ) continue ;

            if ( land[yy][xx] ) {
                ans = min(ans, visited[y][x]) ;
                return ;
            }

            visited[yy][xx] = visited[y][x] + 1 ;
            test.push({yy, xx}) ;
        }
    }
}

void find_bridge(int y, int x) {
    int temp = land[y][x] ;
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( land[i][j] == temp ) {
                test.push({i, j}) ;
            }
        }
    }
    bridgeBFS(temp) ;
    while ( !test.empty() ) test.pop() ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
    
    cin >> n ;

    v.resize(n, vector <int> (n, 0)) ;
    land.resize(n, vector <int> (n, 0)) ;
    visited.resize(n, vector <int> (n, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    find_land() ;

    map <int, int> land_check ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( land[i][j] && !land_check[i*n+j+1] ) {
                land_check[i*n+j+1] = 1 ;

                visited.clear() ;
                visited.resize(n, vector <int> (n, 0)) ;

                find_bridge(i, j) ;
            }
        }
    }

    cout << ans ;

    return 0 ;
}