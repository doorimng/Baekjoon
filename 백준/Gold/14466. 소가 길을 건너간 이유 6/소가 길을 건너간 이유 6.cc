#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, k, r ;

int dx[4] = {0, 1, 0, -1} ;
int dy[4] = {-1, 0, 1, 0} ;

vector <vector <int>> visited ;
vector <vector <vector <int>>> road ;
vector <pii> moo ;

queue <pii> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ; 

            if ( road[y][x][i] ) continue ;

            if ( yy <= 0 || xx <= 0 || yy > n || xx > n ) continue ;
            if ( visited[yy][xx] ) continue ;

            visited[yy][xx] = 1 ;
            q.push({yy, xx}) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> k >> r ;

    road.resize(n+1, vector <vector <int>> (n+1, vector <int> (4, 0))) ;

    for ( int i = 0 ; i < r ; i ++ ) {
        int a, b, c, d ;
        cin >> a >> b >> c >> d ;

        if ( a > c ) {
            road[a][b][0] = 1 ;
            road[c][d][2] = 1 ;
        }
        if ( b < d ) { 
            road[a][b][1] = 1 ;
            road[c][d][3] = 1 ;
        }
        if ( a < c ) {
            road[a][b][2] = 1 ; 
            road[c][d][0] = 1 ;
        }
        if ( b > d ) {
            road[a][b][3] = 1 ;
            road[c][d][1] = 1 ;
        }
    }

    for ( int i = 0 ; i < k ; i ++ ) {
        int y, x ;
        cin >> y >> x ;

        moo.push_back({y, x}) ;
    }

    int cnt = 0 ;
    for ( int i = 0 ; i < moo.size()-1 ; i ++ ) {
        visited.clear() ;
        visited.resize(n+1, vector <int> (n+1, 0)) ;

        q.push(moo[i]) ;
        visited[moo[i].first][moo[i].second] = 1 ;
        BFS() ;

        for ( int j = i+1 ; j < moo.size() ; j ++ ) {
            if ( !visited[moo[j].first][moo[j].second] ) cnt ++ ;
        }
    }

    cout << cnt ;

    return 0 ;
}