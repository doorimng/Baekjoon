#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, l, r ;
vector <vector <int>> board ;
vector <vector <int>> visited ;

int dx[4] = {1, -1, 0, 0} ;
int dy[4] = {0, 0, 1, -1} ;

vector <pii> temp ;
queue <pii> q ;
void BFS() {

    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= n ) continue ;
            if ( visited[yy][xx] ) continue ;
            
            if ( abs(board[y][x] - board[yy][xx]) < l || abs(board[y][x] - board[yy][xx]) > r ) continue ;
            
            visited[yy][xx] = 1 ;
            
            temp.push_back({yy, xx}) ;
            q.push({yy, xx}) ;

        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> l >> r ;

    board.resize(n, vector <int> (n, 0)) ;
    visited.resize(n, vector <int> (n, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> board[i][j] ;
        }
    }

    int cnt = 0, openCnt = 0 ;
    while ( true ) {

        visited.clear() ;
        visited.resize(n, vector <int> (n, 0)) ;
        
        openCnt = 0 ;
        
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < n ; j ++ ) {
                if ( !visited[i][j] ) {
                    q.push({i, j}) ;
                    temp.push_back({i, j}) ;
                    visited[i][j] = 1 ;
                    
                    BFS() ;
                    
                    if ( temp.size() > 1 ) openCnt ++ ;
                    
                    int sum = 0 ;
                    for ( int k = 0 ; k < temp.size() ; k ++ ) {
                        int y = temp[k].first ;
                        int x = temp[k].second ;
                        
                        sum += board[y][x] ;
                    }
                    for ( int k = 0 ; k < temp.size() ; k ++ ) {
                        int y = temp[k].first ;
                        int x = temp[k].second ;
                        
                        board[y][x] = sum / temp.size() ;
                    }
                    temp.clear() ;
                    
                }
            }
        }

        if ( !openCnt ) break ;
        cnt ++ ;
    }
    
    cout << cnt ;

    return 0 ;
}