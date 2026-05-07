#include <iostream>
#include <vector>
#include <queue>

using namespace std ;

int N, M, Mx = 0 ;

int dx[4] = {1, 0, -1, 0} ;
int dy[4] = {0, 1, 0, -1} ;

vector <vector <int>> v ;
vector <vector <int>> visited ;

queue <pair <int, int>> q ;
void BFS() {
    int cnt = 1 ;
    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;
    
        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= N || xx < 0 || xx >= M ) continue ;
            if ( visited[yy][xx] || v[yy][xx] != v[y][x] ) continue ;

            cnt ++ ;
            visited[yy][xx] = 1 ;
            q.push({yy, xx}) ;
        }
    }
    Mx = max(Mx, cnt) ;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int n, int m, vector<vector<int>> picture) {
    int cnt = 0 ;
    
    Mx = 0 ;
    N = n ;
    M = m ;

    v = picture ;
    visited.clear() ;
    visited.resize(n+1, vector <int> (m+1, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            if ( !visited[i][j] && v[i][j] ) {
                visited[i][j] = 1 ;
                q.push({i, j}) ;
                BFS() ;
                cnt ++ ;
            }
        }
    }

    return {cnt, Mx} ;
}