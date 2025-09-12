#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct info {
    int y ;
    int x ;
    int horseMove ;
    int cnt ;
} ;

int k, w, h, ans = INF ;
vector <vector <int>> board ;
vector <vector <vector <int>>> visited ; // {y, x, 말 이동 횟수}

int dx[12] = {-2, -1, 1, 2, -2, -1, 1, 2, 1, -1, 0, 0} ;
int dy[12] = {-1, -2, -2, -1, 1, 2, 2, 1, 0, 0, 1, -1} ;

queue <info> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().y ;
        int x = q.front().x ;
        int horse_move = q.front().horseMove ;
        int cnt = q.front().cnt ;
        q.pop() ;

        if ( y == h-1 && x == w-1 ) {
            ans = min(ans, cnt) ;
            return ;
        }
        
        for ( int i = 0 ; i < 12 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= h || xx < 0 || xx >= w ) continue ;
            if ( board[yy][xx] ) continue ;

            if ( i < 8 ) {
                if ( horse_move+1 > k ) continue ;
                if ( visited[yy][xx][horse_move+1] != INF ) continue ;
                
                q.push({yy, xx, horse_move+1, cnt+1}) ;
                visited[yy][xx][horse_move+1] = cnt+1 ;
            } 
            else {
                if ( visited[yy][xx][horse_move] != INF ) continue ;
                
                q.push({yy, xx, horse_move, cnt+1}) ;
                visited[yy][xx][horse_move] = cnt+1 ;
            }

        }
    }
    return ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> k >> w >> h ;
    board.resize(h+1, vector <int> (w+1, 0)) ;
    visited.resize(h+1, vector <vector <int>> (w+1, vector <int> (k+1, INF))) ;

    for ( int i = 0 ; i < h ; i ++ ) {
        for ( int j = 0 ; j < w ; j ++ ) {
            cin >> board[i][j] ;
        }
    }

    q.push({0, 0, 0, 0}) ;
    visited[0][0] = {0, } ;
    BFS() ;

    if ( ans == INF ) cout << -1 ;
    else cout << ans ;

    return 0 ;
}