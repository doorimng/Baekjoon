#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, Mn = INF ;

// 동 남 서 북
// 0  1  2  3
int dx[4] = {1, 0, -1, 0} ; 
int dy[4] = {0, 1, 0, -1} ;

vector <vector <char>> v ;
vector <vector <vector <pii>>> visited ;

struct info {
    int y ;
    int x ;
    int dir ;
    int mirror ;
} ;

queue <info> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().y ;
        int x = q.front().x ;
        int dir = q.front().dir ;
        int mirror = q.front().mirror ;
        q.pop() ;

        int yy = y + dy[dir] ;
        int xx = x + dx[dir] ;

        if ( yy < 0 || yy >= n || xx < 0 || xx >= n ) continue ;
        if ( v[yy][xx] == '*' ) continue ;

        if ( visited[yy][xx][dir].first ) {
            if ( visited[yy][xx][dir].second <= mirror ) continue ;
        }

        if ( v[yy][xx] == '#' ) Mn = min(mirror, Mn) ;
        else if ( v[yy][xx] == '!' ) {
            for ( int i = 0 ; i < 4 ; i ++ ) {
                if ( i == 2 ) continue ;

                visited[yy][xx][(dir+i) % 4] = {1, min(visited[yy][xx][(dir+i) % 4].second, mirror)} ;

                if ( i == 0 ) q.push({yy, xx, dir, mirror}) ;
                else q.push({yy, xx, (dir+i) % 4, mirror+1}) ;
            }
        }
        else {
            visited[yy][xx][dir] = {1, min(visited[yy][xx][dir].second, mirror)} ;
            q.push({yy, xx, dir, mirror}) ;
        }
    }
    return ;
}

pii start ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;

    v.resize(n, vector <char> (n, 0)) ;
    visited.resize(n, vector <vector <pii>> (n, vector <pii> (4, {0, INF}))) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> v[i][j] ;

            if ( v[i][j] == '#' ) start = {i, j} ;
        }
    }

    v[start.first][start.second] = '.' ;

    for ( int i = 0 ; i < 4 ; i ++ ) {
        q.push({start.first, start.second, i, 0}) ;
    }
    BFS() ;

    cout << Mn ;

    return 0 ;
}