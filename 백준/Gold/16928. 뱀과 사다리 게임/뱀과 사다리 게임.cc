#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m, ans = INF ;

map <int, int> ladder ;
map <int, int> snake ;

vector <int> visited (101, INF) ;

queue <pii> q ;
void BFS() {
    while ( !q.empty() ) {
        int cur = q.front().first ;
        int cnt = q.front().second ;
        q.pop() ;

        for ( int i = 1 ; i <= 6 ; i ++ ) {
            int next = cur + i ;

            if ( ladder[next] ) next = ladder[next] ;
            else ladder.erase(next) ;
            
            if ( snake[next] ) next = snake[next] ;
            else snake.erase(next) ;

            if ( next > 100 ) break ;
            if ( next == 100 ) {
                ans = min(ans, cnt+1) ;
                continue ;
            }
            
            if ( visited[next] != INF && visited[next] <= cnt+1 ) continue ;

            visited[next] = min(visited[next], cnt+1) ;
            q.push({next, cnt+1}) ;
        }
    }
}

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    cin >> n >> m ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        ladder[a] = b ;
    }

    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        snake[a] = b ;
    }

    visited[1] = 0 ;
    q.push({1, 0}) ;
    BFS() ;

    cout << ans ;

    return 0 ;
}