#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

int w, h ;
vector <vector <char>> v ;
vector <vector <int>> fire ;
queue <pii> q ;

void Fire() {
    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= h || xx < 0 || xx >= w ) continue ;
            if ( fire[yy][xx] != INF || v[yy][xx] == '#' ) continue ;

            fire[yy][xx] = fire[y][x] + 1 ;
            q.push({yy, xx}) ;
        }
    }
}

vector <vector <int>> sanggeun ;
queue <pii> sg_q ;
int ans = INF ;
void BFS() {
    while ( !sg_q.empty() ) {
        int y = sg_q.front().first ;
        int x = sg_q.front().second ;
        sg_q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= h || xx < 0 || xx >= w ) {
                ans = min(ans, sanggeun[y][x]) ;
                continue ;
            }
            if ( v[yy][xx] == '#' || sanggeun[yy][xx] != INF ) continue ;
            if ( sanggeun[y][x] + 1 >= fire[yy][xx] ) continue ;
            sanggeun[yy][xx] = sanggeun[y][x] + 1 ;

            
            sg_q.push({yy, xx}) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        cin >> w >> h ;

        v.clear() ;
        v.resize(h, vector <char> (w, 0)) ;
        fire.clear() ;
        fire.resize(h, vector <int> (w, INF)) ;
        sanggeun.clear() ;
        sanggeun.resize(h, vector <int> (w, INF)) ;

        for ( int i = 0 ; i < h ; i ++ ) {
            for ( int j = 0 ; j < w ; j ++ ) {
                cin >> v[i][j] ;

                if ( v[i][j] == '*' ) {
                    fire[i][j] = 1 ;
                    q.push({i, j}) ;
                }
                if ( v[i][j] == '@' ) {
                    sanggeun[i][j] = 1 ;
                    sg_q.push({i, j}) ;
                }
            }
        }

        Fire() ; 
        BFS() ;

        if ( ans == INF ) cout << "IMPOSSIBLE\n" ;
        else cout << ans << "\n" ;

        ans = INF ;
    }

    return 0 ;
}