#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, ans = INF ;
vector <int> v ;
vector <vector <int>> visited ;

struct info {
    int emoji ;
    int clipboard ;
    int cnt ;
} ;

queue <info> q ;
void BFS() {
    while ( !q.empty() ) {
        int emoji = q.front().emoji ;
        int clipboard = q.front().clipboard ;
        int cnt = q.front().cnt ;
        q.pop() ;

        if ( emoji == n ) {
            ans = min(ans, cnt) ;
            continue ;
        }
        if ( emoji > 2*n ) continue ;

        if ( visited[emoji][clipboard] <= cnt ) continue ;

        visited[emoji][clipboard] = cnt ;
        
        if ( clipboard ) {
            q.push({emoji+clipboard, clipboard, cnt+1}) ;
        }   
        
        q.push({emoji, emoji, cnt+1}) ;

        if ( emoji ) {
            q.push({emoji-1, clipboard, cnt+1}) ;
        }

    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;
    v.resize(3000, 0) ;
    visited.resize(3000, vector <int> (3000, INF)) ;

    q.push({1, 0, 1}) ;
    BFS() ;

    cout << ans-1 ;

    return 0 ;
}