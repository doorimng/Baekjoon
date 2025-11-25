#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

int n, m, ans = 0 ;
vector <vector <int>> v ;
vector <pair <pii, int>> cheese ;

queue <pii> qu ; 
void findAirBFS() {
    while ( !qu.empty() ) {
        int y = qu.front().first ;
        int x = qu.front().second ;
        qu.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
            if ( v[yy][xx] == 0 ) {
                v[yy][xx] = -1 ;
                qu.push({yy, xx}) ;
            }
        }
    }
}

queue <pii> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().first ;
        int x = q.front().second ;
        q.pop() ;

        v[y][x] = -1 ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;
            if ( v[yy][xx] == 0 ) {
                v[yy][xx] = -1 ;
                q.push({yy, xx}) ;
            }
        }

    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m ;
    v.resize(n, vector <int> (m, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> v[i][j] ;

            if ( v[i][j] == 1 ) cheese.push_back({{i, j}, 0}) ;
        }
    }

    qu.push({0, 0}) ;
    findAirBFS() ;
    
    int finish = cheese.size() ;
    while ( finish ) {
        for ( int i = 0 ; i < cheese.size() ; i ++ ) {

            if ( cheese[i].second ) continue ;

            int y = cheese[i].first.first ;
            int x = cheese[i].first.second ;
            
            int cnt = 0 ;
            for ( int j = 0 ; j < 4 ; j ++ ) {
                int yy = y + dy[j] ;
                int xx = x + dx[j] ;

                // 가장자리 접근할 일이 없음
                // if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;

                if ( v[yy][xx] == -1 ) cnt ++  ;
            }

            if ( cnt >= 2 ) {
                finish -- ;
                cheese[i].second = 1 ;
                q.push({y, x}) ;
            }
        }
        ans ++ ;
        BFS() ;
    }

    cout << ans ;

    return 0 ;
}