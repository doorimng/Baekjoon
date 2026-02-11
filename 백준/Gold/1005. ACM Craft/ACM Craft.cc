#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n ;
vector <pii> head ; 
vector <int> times ;
vector <int> ans ;
vector <int> visited ;
vector <vector <int>> v ;

queue <pii> q ;
void BFS() {
    while ( !q.empty() ) {
        int cur = q.front().first ;
        int t = q.front().second ;
        ans[cur] = min(ans[cur], t) ;
        q.pop() ;

        for ( int next : v[cur] ) {
            if ( !visited[next] ) {
                head[next].first -- ;
                head[next].second = max(head[next].second, t) ;
                if ( !head[next].first ) {
                    q.push({next, times[next]+head[next].second}) ;
                    visited[next] = 1 ;
                }
            }
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;
    
    while ( t -- ) {
        int n, k ;
        cin >> n >> k ;
        
        head.clear() ;
        times.clear() ;
        ans.clear() ;
        v.clear() ;
        visited.clear() ;

        head.resize(n+1, {0, 0}) ;
        times.resize(n+1, 0) ;
        ans.resize(n+1, INF) ;
        v.resize(n+1, vector <int> (0)) ;
        visited.resize(n+1, 0) ;

        for ( int i = 1 ; i <= n ; i ++ ) cin >> times[i] ;

        for ( int i = 0 ; i < k ; i ++ ) {
            int a, b ;
            cin >> a >> b ;

            v[a].push_back(b) ;
            head[b].first ++ ;
        }

        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( !head[i].first ) {
                visited[i] = 1 ;
                q.push({i, times[i]}) ;
            }
        }

        BFS() ;

        int w ;
        cin >> w ;

        cout << ans[w] << "\n" ;
    }

    return 0 ;
}