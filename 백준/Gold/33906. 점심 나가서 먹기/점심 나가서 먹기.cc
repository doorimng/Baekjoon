#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <ll, ll> pii ;
#define INF (ll) LLONG_MAX

int n, m ;

vector <vector <pii>> node ;
vector <ll> minCost ;
vector <int> visited ;

void dijk(ll start) {
    
    // visited[start] = 1 ;
    minCost[start] = 0 ;

    priority_queue <pii, vector <pii>, greater<>> pq ;
    pq.push({0, start}) ;

    while ( !pq.empty() ) {
        pii temp = pq.top() ;
        pq.pop() ;

        if ( !visited[temp.second] ) {
            visited[temp.second] = 1 ;

            for ( pii x : node[temp.second] ) {
                if ( minCost[x.second] > temp.first + x.first ) {
                    minCost[x.second] = temp.first + x.first ;
                    pq.push({minCost[x.second], x.second}) ;
                }
            }
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m ;

    vector <int> restaurant (n+1, 0) ;
    vector <int> cafe (n+1, 0) ;

    for ( int i = 1 ; i <= n ; i ++ ) cin >> restaurant[i] ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> cafe[i] ;
    
    node.resize(n+1, vector <pii> (0)) ;
    minCost.resize(n+1, INF) ;
    visited.resize(n+1, 0) ;
    
    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b, c ;
        cin >> a >> b >> c ;
        
        node[a].push_back({c, b}) ;
        node[b].push_back({c, a}) ;
    }
    
    dijk(1) ;
    
    ll Mnrest = INF, Mncafe = INF, restnode, cafenode ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( visited[i] && restaurant[i] != 0 ) {
            if ( restaurant[i] < Mnrest ) {
                Mnrest = restaurant[i] ;
                restnode = i ;
            }
        }
        if ( visited[i] && cafe[i] != 0 ) {
            if ( cafe[i] < Mncafe ) {
                Mncafe = cafe[i] ;
                cafenode = i ;
            }
        }
    }

    ll ansCost = (ll) minCost[restnode] + (ll) minCost[cafenode] ;

    minCost.clear() ;
    visited.clear() ;
    minCost.resize(n+1, INF) ;
    visited.resize(n+1, 0) ;

    dijk(restnode) ;

    ansCost += (ll) minCost[cafenode] ;

    cout << ansCost ;

    return 0 ;
}