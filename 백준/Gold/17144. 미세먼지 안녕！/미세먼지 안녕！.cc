#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX 

int n, m, t ;
pii up = {-1, -1}, down = {-1, -1} ;

// 서 북 동 남
int dx[4] = {-1, 0, 1, 0} ;
int dy[4] = {0, -1, 0, 1} ;

vector <vector <int>> room ;
vector <vector <int>> add ;

void Refresh(int y, int x, int dir, int upper) {

    int yy = y + dy[dir] ;
    int xx = x + dx[dir] ;


    if ( upper == 1 ) {
        if ( yy < 0 || yy > up.first || xx < 0 || xx >= m ) {
            dir = (dir+upper) % 4 ;
    
            yy = y + dy[dir] ;
            xx = x + dx[dir] ;
        }
    }
    else {
        if ( yy < down.first || yy >= n || xx < 0 || xx >= m ) {
            dir = (dir+upper) % 4 ;
    
            yy = y + dy[dir] ;
            xx = x + dx[dir] ;
        }
    }

    if ( room[y][x] == -1 ) room[yy][xx] = 0 ;
    else {
        if ( room[yy][xx] == -1 ) {
            room[y][x] = 0 ;
            return ;
        }
        else room[y][x] = room[yy][xx] ;
    }

    Refresh(yy, xx, dir, upper) ;
    

}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m >> t ;

    room.resize(n+1, vector <int> (m+1, 0)) ;
    add.resize(n+1, vector <int> (m+1, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            int x ;
            cin >> x ;

            room[i][j] = x ;

            if ( x == -1 ) {
                if ( up.first == -1 ) up = {i, j} ;
                else down = {i, j} ;
            }
        }
    }

    while ( t -- ) {
        // 미세먼지 확산

        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                if ( room[i][j] > 0 ) {
                    int cnt = 0 ;

                    for ( int k = 0 ; k < 4 ; k ++ ) {
                        int yy = i + dy[k] ; 
                        int xx = j + dx[k] ;

                        if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
                        if ( room[yy][xx] == -1 ) continue ;

                        add[yy][xx] += room[i][j] / 5 ;
                        cnt ++ ;
                    }

                    room[i][j] -= ( room[i][j] / 5 ) * cnt ;
                }
            }
        }

        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
                room[i][j] += add[i][j] ;
                add[i][j] = 0 ;
                // cout << room[i][j] + add[i][j] << " " ;
            }
            // cout << "\n" ;
        }

        // 공기청정기
        Refresh(up.first, up.second, 1, 1) ;
        Refresh(down.first, down.second, 3, 3) ;
    }

    int sum = 2 ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            sum += room[i][j] ;
            // cout << room[i][j] << " " ;
        }
        // cout << "\n" ;
    }

    cout << sum ;

    return 0 ;
}