#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, e ;

vector <vector <pii>> node ;
vector <int> visited ;
vector <int> ans ;

vector <int> start ;

priority_queue <pii, vector <pii>, greater<pii>> pq ;

void Dijk() {
    while ( !pq.empty() ) {
        int curNode = pq.top().second ;
        int cost = pq.top().first ;
        visited[curNode] = 1 ;
        pq.pop() ;

        if ( ans[curNode] < cost ) continue ;
    
        for ( int i = 0 ; i < node[curNode].size() ; i ++ ) {
            int nextNode = node[curNode][i].first ;
            int nextCost = node[curNode][i].second ;

            if ( visited[nextNode] ) continue ;

            if ( ans[nextNode] > nextCost + ans[curNode]) {
                ans[nextNode] = nextCost + ans[curNode] ;
                pq.push({ans[nextNode], nextNode}) ;
            }
        }
    
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> e ;

    node.resize(n+1) ;
    visited.resize(n+1, 0) ;
    ans.resize(n+1, INF) ;
    start.resize(n+1, INF) ;

    for ( int i = 0 ; i < e ; i ++ ) {
        int a, b, c ;
        cin >> a >> b >> c ;

        node[a].push_back({b, c}) ;
        node[b].push_back({a, c}) ;
    }

    int v1, v2, sum = 0 ;
    cin >> v1 >> v2 ;

    ans[v1] = 0 ;
    pq.push({0, v1}) ; 
    Dijk() ; 

    if ( ans[v2] == INF ) {
        cout << -1 ;
        return 0 ;
    }
    sum += ans[v2] ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        start[i] = ans[i] ;
        visited[i] = 0 ;
        ans[i] = INF ;
    }

    ans[v2] = 0 ;
    pq.push({0, v2}) ;

    Dijk() ; 

    int a = INF, b = INF ;
    if ( start[1] != INF && ans[n] != INF ) a = start[1] + ans[n] ;
    if ( start[n] != INF && ans[1] != INF ) b = start[n] + ans[1] ;

    if ( min(a, b) == INF ) cout << -1 ;
    else cout << sum + min(a, b) ;

    return 0 ;
}