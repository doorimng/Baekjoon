#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <char>> v (10, vector <char> (10, ' ')) ;
vector <vector <int>> visited (10, vector <int> (10, 0)) ;

int dy[9] = {-1, -1, -1,  0, 0, 0,  1, 1, 1} ;
int dx[9] = {-1,  0,  1, -1, 0, 1, -1, 0, 1} ;

struct info {
    int y ;
    int x ;
    int wall ;  
} ;

queue <info> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().y ;
        int x = q.front().x ;
        int wall = q.front().wall ;
        q.pop() ;

        for ( int i = 0 ; i < 9 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= 8 || xx < 0 || xx >= 8 ) continue ;
            if ( visited[yy][xx] > 8 ) continue ;

            if ( yy-wall >= 0 && v[yy-wall][xx] == '#' ) continue ;
            if ( yy-wall-1 >= 0 && v[yy-wall-1][xx] == '#' ) continue ;

            visited[yy][xx] ++ ;
            q.push({yy, xx, wall+1}) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    for ( int i = 0 ; i < 8 ; i ++ ) {
        for ( int j = 0 ; j < 8 ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    visited[7][0] = 1 ;
    q.push({7, 0, 0}) ;
    BFS() ;

    if ( visited[0][7] ) visited[0][7] = 1 ;
    cout << visited[0][7] ;

    return 0 ;
}