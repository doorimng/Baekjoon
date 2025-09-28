#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

int r, c ;
vector <vector <char>> v ;
vector <vector <int>> ice ;
vector <vector <int>> swan ;

queue <pii> q ;
int Mn = 0, Mx = 1 ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || xx < 0 || yy >= r || xx >= c ) continue ;

            if ( !ice[yy][xx] && v[yy][xx] == 'X' ) {
                ice[yy][xx] = ice[y][x] + 1 ;
                Mx = max(Mx, ice[yy][xx]) ;
                q.push({yy, xx}) ; 
            }
        }
    }
}

queue <pii> sq ;
void SwanBFS(int mid) {
    while ( !sq.empty() ) {
        int y = sq.front().first ;
        int x = sq.front().second ;
        sq.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || xx < 0 || yy >= r || xx >= c ) continue ;
            if ( ice[yy][xx] > mid || swan[yy][xx] ) continue ;

            swan[yy][xx] = 1 ;
            sq.push({yy, xx}) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> r >> c ;
    v.resize(r, vector <char> (c, 0)) ;
    ice.resize(r, vector <int> (c, 0)) ;
    swan.resize(r, vector <int> (c, 0)) ;

    vector <pii> L ;

    for ( int i = 0 ; i < r ; i ++ ) {
        for ( int j = 0 ; j < c ; j ++ ) {
            cin >> v[i][j] ;

            if ( v[i][j] == 'L' ) L.push_back({i, j}) ;
        }
    }

    for ( int i = 0 ; i < r ; i ++ ) {
        for ( int j = 0 ; j < c ; j ++ ) {
            if ( v[i][j] == 'X' ) {
                int check = 0 ;
                for ( int k = 0 ; k < 4 ; k ++ ) {
                    int yy = i + dy[k] ;
                    int xx = j + dx[k] ;
    
                    if ( yy < 0 || yy >= r || xx < 0 || xx >= c ) continue ;
    
                    if ( v[yy][xx] == '.' || v[yy][xx] == 'L' ) check = 1 ;
                }
    
                if ( check ) {
                    ice[i][j] = 1 ;
                    q.push({i, j}) ;
                }
            }
        }
    }

    BFS() ;

    int ans = INF ;
    while ( Mn <= Mx ) {
        int mid = (Mn + Mx) / 2 ;

        swan.clear() ;
        swan.resize(r, vector <int> (c, 0)) ;

        sq.push(L[0]) ;
        SwanBFS(mid) ;

        if ( swan[L[1].first][L[1].second] ) {
            ans = min(ans, mid) ;
            Mx = mid - 1 ;
        }
        else Mn = mid + 1 ;
    }

    cout << ans ;

    return 0 ;
}