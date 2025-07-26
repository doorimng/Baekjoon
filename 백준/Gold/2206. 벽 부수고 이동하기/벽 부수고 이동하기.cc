#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <int>> board ;
vector <vector <pii>> visited ;

int n, m ;
int dx[4] = {1, -1, 0, 0} ;
int dy[4] = {0, 0, 1, -1} ;

struct info {
    int y ;
    int x ;
    int is_break = 0 ;
} ;

int ans = INF ;

queue <info> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().y ;
        int x = q.front().x ;
        int is_break = q.front().is_break ;
        q.pop() ;

        if ( y == n && x == m ) ans = min(ans, visited[y][x].first) ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy <= 0 || yy > n || xx <= 0 || xx > m ) continue ;

            if ( is_break ) { // 지금까지 부순 적 있으면
                // 벽은 다시 탐색 X
                if ( board[yy][xx] == 1 ) continue;
                else {
                    if ( visited[yy][xx].first ) {
                        // continue ;
                        // 벽 안 부수고 방문한 적이 있는 경우
                        if ( visited[yy][xx].second == 0 ) {
                            // 벽 안 부순 상태로 갱신 + 재탐색 (흠..)
                            visited[yy][xx] = {visited[yy][xx].first, 0} ;
                            q.push({yy, xx, 0}) ;
                        } 
                        // 벽 부수고 방문한 적이 있는 경우
                        // 이전 방법이 최선이므로 할 필요 X
                        else continue ; 
                    }
                    else { // 방문한 적 없는 칸일 경우
                        visited[yy][xx] = {visited[y][x].first + 1, 1} ;
                        q.push({yy, xx, 1}) ;
                    }
                }

                // 1번 있던 곳 
            }
            else { // 지금까지 부순 적 없으면
                if ( board[yy][xx] == 1 ) { // 벽을 만날 경우
                    if ( visited[yy][xx].first ) continue ;
                    visited[yy][xx] = {visited[y][x].first + 1, 1} ;
                    q.push({yy, xx, 1}) ;
                }
                else { 
                    if ( visited[yy][xx].first ) {
                        if ( visited[yy][xx].second ) {
                            visited[yy][xx] = {visited[y][x].first + 1, 0} ;
                            q.push({yy, xx, 0}) ;   
                        }
                        else continue ;
                    }
                    else {
                        visited[yy][xx] = {visited[y][x].first + 1, 0} ;
                        q.push({yy, xx, 0}) ;
                    }
                }
            }
        }
    }
    return ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m ;

    board.resize(n+1, vector <int> (m+1, 0)) ;
    visited.resize(n+1, vector <pii> (m+1, {0, 0})) ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            char c ;
            cin >> c ;

            board[i][j] = c-'0' ;
        }
    }

    
    q.push({1, 1, 0}) ;
    visited[1][1] = {1, 0} ;
    BFS() ;

    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     for ( int j = 1 ; j <= m ; j ++ ) {
    //         cout << visited[i][j].first << "\t" ;
    //     }
    //     cout << "\n" ;
    // }

    // if ( visited[n][m].first == 0 ) cout << -1 ;
    // else cout << visited[n][m].first ;

    // cout << "\n" << ans << " <== ans" ;

    if ( ans == INF ) cout << -1 ;
    else cout << ans ;

    return 0 ;
}