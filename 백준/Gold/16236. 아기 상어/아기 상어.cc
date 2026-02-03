#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n ;
vector <vector <int>> v ;
vector <vector <int>> visited ;

int dx[4] = {0, -1, 1, 0} ;
int dy[4] = {-1, 0, 0, 1} ;

struct info {
    int y ;
    int x ;
    int size ;
    int cnt ;
} ;
info baby_shark ;

struct cmp {
    bool operator()(info a, info b) {
        if ( a.y != b.y ) return a.y > b.y ;
        else return a.x > b.x ;
    }
} ;

priority_queue <info, vector <info>, cmp> pq ;
queue <info> q ;
void BFS() {
    while ( !q.empty() ) {
        int y = q.front().y ;
        int x = q.front().x ;
        int size = q.front().size ;
        int cnt = q.front().cnt ;
        q.pop() ;

        for ( int i = 0 ; i < 4 ; i ++ ) {
            int yy = y + dy[i] ;
            int xx = x + dx[i] ;

            if ( yy < 0 || xx < 0 || yy >= n || xx >= n ) continue ;
            if ( visited[yy][xx] != INF  ) continue ;
            if ( v[yy][xx] > size ) continue ;

            visited[yy][xx] = visited[y][x] + 1 ;
            
            if ( v[yy][xx] && v[yy][xx] < size ) {
                if ( pq.empty() ) pq.push({yy, xx, size, cnt+1}) ;
                else {
                    if ( visited[yy][xx] <= visited[pq.top().y][pq.top().x] )
                        pq.push({yy, xx, size, cnt+1}) ;
                }
            }
            else {
                if ( pq.empty() ) {
                    q.push({yy, xx, size, cnt}) ;
                }
            }
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;

    v.resize(n+1, vector <int> (n+1, 0)) ;
    visited.resize(n+1, vector <int> (n+1, INF)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> v[i][j] ;
        
            if ( v[i][j] == 9 ) {
                pq.push({i, j, 2, 0}) ;
                visited[i][j] = 0 ;
            }
        }
    }

    int times = 0 ;
    while ( true ) {
        
        baby_shark = pq.top() ;
        while ( !pq.empty() ) pq.pop() ;
        
        times += visited[baby_shark.y][baby_shark.x] ;

        if ( baby_shark.cnt >= baby_shark.size ) {
            baby_shark.cnt -= baby_shark.size ;
            baby_shark.size ++ ;
        }
        
        visited.clear() ;
        visited.resize(n+1, vector <int> (n+1, INF)) ;

        q.push(baby_shark) ;
        v[baby_shark.y][baby_shark.x] = 0 ;
        visited[baby_shark.y][baby_shark.x] = 0 ;
        BFS() ;
        
        if ( pq.empty() ) break ;
    }

    cout << times ;

    return 0 ;
}