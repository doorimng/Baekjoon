#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

int n, m ;
vector <vector <char>> v ;
vector <vector <int>> watered ;
vector <vector <int>> visited ;

struct info {
    int y ;
    int x ;
} ;

queue <info> q ;
void waterBFS() {
    while ( !q.empty() ) {
        int y = q.front().y ;
        int x = q.front().x ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ; 
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
            if ( watered[yy][xx] > -1 ) continue ; // 이미 방문
            if ( v[yy][xx] == 'X' || v[yy][xx] == 'D' ) continue ; // 돌이거나 굴

            watered[yy][xx] = watered[y][x] + 1 ;
            q.push({yy, xx}) ;
        }
    }
}

void BFS() {
    while ( !q.empty() ) {
        int y = q.front().y ;
        int x = q.front().x ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ; 
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
            if ( visited[yy][xx] > -1 || v[yy][xx] == 'X' ) continue ;
            if ( watered[yy][xx] != -1 && watered[yy][xx] <= visited[y][x] + 1 ) continue ;

            visited[yy][xx] = visited[y][x] + 1 ;
            q.push({yy, xx}) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m ;
    v.resize(n, vector <char> (m, 0)) ;
    watered.resize(n, vector <int> (m, -1)) ;
    visited.resize(n, vector <int> (m, -1)) ;

    info start, end ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> v[i][j] ;

            if ( v[i][j] == 'S' ) start = {i, j} ;
            if ( v[i][j] == 'D' ) end = {i, j} ;
            if ( v[i][j] == '*' ) {
                watered[i][j] = 0 ;
                q.push({i, j}) ;
            }
        }
    }

    waterBFS() ;

    q.push(start) ;
    visited[start.y][start.x] = 0 ;
    BFS() ;

    if ( visited[end.y][end.x] > -1 ) cout << visited[end.y][end.x] ;
    else cout << "KAKTUS" ;

    return 0 ;
}