#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, k, m, Mn = INF ;

vector <vector <int>> v ;
vector <int> visited ;

queue <pii> q ;
void BFS() {
    while ( !q.empty() ) {
        int temp = q.front().first ;
        int cnt = q.front().second ;
        q.pop() ;

        if ( temp == n ) Mn = min(Mn, cnt) ;

        for ( int x : v[temp] ) {
            if ( !visited[x] ) {
                if ( x <= n ) {
                    visited[x] = 1 ;
                    q.push({x, cnt+1}) ;
                }
                else q.push({x, cnt}) ;
            }
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> k >> m ;

    visited.resize(n+m+1, 0) ;
    v.resize(n+m+1, vector <int> (0)) ;

    for ( int i = n+1 ; i < n+m+1 ; i ++ ) {
        for ( int j = 0 ; j < k ; j ++ ) {
            int x ;
            cin >> x ;

            v[x].push_back(i) ;
            v[i].push_back(x) ;
        }
    }

    q.push({1, 1}) ;
    BFS() ;

    if ( Mn == INF ) cout << -1 ;
    else cout << Mn ;

    return 0 ;
}