#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

int n, m, a, b, k ;
vector <vector <int>> v ;
vector <vector <int>> visited ;

struct info {
    int y ;
    int x ;
    int cnt ;
} ;

queue <info> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().y ;
        int x = q.front().x ;
        int cnt = q.front().cnt ;
        q.pop() ;

        
        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy <= 0 || xx <= 0 || yy+a > n+1 || xx+b > m+1 ) continue ;
            if ( visited[yy][xx] > -1 || v[yy][xx] ) continue ;

            visited[yy][xx] = cnt+1 ;
            q.push({yy, xx, cnt+1}) ;
        }
    }
}

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    cin >> n >> m >> a >> b >> k ;

    v.resize(505, vector <int> (505, 0)) ;
    visited.resize(505, vector <int> (505, -1)) ;

    for ( int i = 0 ; i < k ; i ++ ) {
        int y, x ;
        cin >> y >> x ;

        for ( int j = 1-a ; j <= 0 ; j ++ ) { 
            for ( int k = 1-b ; k <= 0 ; k ++ ) { 
                int yy = y + j ;
                int xx = x + k ;

                if ( yy <= 0 || xx <= 0 || yy+a > n+1 || xx+b > m+1 ) continue ;
                
                v[yy][xx] = 1 ;
            }
        }
    }

    int sy, sx, ey, ex ;
    cin >> sy >> sx >> ey >> ex ;

    q.push({sy, sx, 0}) ;
    visited[sy][sx] = 0 ;
    BFS() ;

    cout << visited[ey][ex] ;

    return 0 ;
}