#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n ;
vector <vector <pii>> v ;
vector <int> leaf ;
vector <int> visited ;

int ans = 0 ;
void DFS(int n, int sum) {
    ans = max(ans, sum) ;
    for ( pii x : v[n] ) {
        if ( !visited[x.first] ) {
            int nextNode = x.first ;
            int cost = x.second ;
            
            visited[x.first] = 1 ;

            DFS(nextNode, sum+cost) ;
            
            visited[nextNode] = 0 ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;
    v.resize(n+1, vector <pii> (0)) ;
    leaf.resize(n+1, 1) ;
    visited.resize(n+1, 0) ;

    leaf[1] = 0 ;

    for ( int i = 1 ; i < n ; i ++ ) {
        int a, b, c ;
        cin >> a >> b >> c ;

        v[a].push_back({b, c}) ;
        v[b].push_back({a, c}) ;

        leaf[a] = 0 ;
    }

    int Mx = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( leaf[i] ) {
            visited[i] = 1 ;
            DFS(i, 0) ;
            Mx = max(Mx, ans) ;
            ans = 0 ;
            visited[i] = 0 ;
        }
    }

    cout << Mx ;

    return 0 ;
}