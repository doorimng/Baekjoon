#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int lz, ry, cx ;
int dz[6] = {0,  0, 0,  0, 1, -1} ;
int dy[6] = {1, -1, 0,  0, 0,  0} ;
int dx[6] = {0,  0, 1, -1, 0,  0} ;

vector <vector <vector <char>>> v ;
vector <vector <vector <int>>> visited ;

struct xyz {
    int z ;
    int y ;
    int x ;
} ;

queue <xyz> q ;
void BFS() {
    while ( !q.empty() ) {
        int z = q.front().z ;
        int y = q.front().y ;
        int x = q.front().x ;
        q.pop() ;

        for ( int i = 0 ; i < 6 ; i ++ ) {
            int zz = z + dz[i] ; 
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( zz >= lz || zz < 0 || xx >= cx || xx < 0 || yy >= ry || yy < 0 ) continue ;
            if ( v[zz][yy][xx] == '#' || visited[zz][yy][xx] ) continue ;

            visited[zz][yy][xx] = visited[z][y][x] + 1 ;
            q.push({zz, yy, xx}) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
    
    while ( true ) {
        cin >> lz >> ry >> cx ;

        if ( lz == 0 && ry == 0 && cx == 0 ) break ;

        v.clear() ;
        v.resize(lz, vector <vector <char>> (ry, vector <char> (cx, 0))) ;
        visited.clear() ;
        visited.resize(lz, vector <vector <int>> (ry, vector <int> (cx, 0))) ;

        xyz finish ;
        for ( int i = 0 ; i < lz ; i ++ ) {
            for ( int j = 0 ; j < ry ; j ++ ) {
                for ( int k = 0 ; k < cx ; k ++ ) {
                    cin >> v[i][j][k] ;

                    if ( v[i][j][k] == 'S' ) q.push({i, j, k}) ;
                    if ( v[i][j][k] == 'E' ) finish = {i, j, k} ;
                }
            }
        }

        BFS() ;

        if ( visited[finish.z][finish.y][finish.x] ) 
            cout << "Escaped in " << visited[finish.z][finish.y][finish.x] << " minute(s).\n" ;
        else cout << "Trapped!\n" ;
    }

    return 0 ;
}