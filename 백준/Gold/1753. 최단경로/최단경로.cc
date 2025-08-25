#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int v, e, k ;

vector <vector <pii>> node ;
vector <int> visited ;
vector <int> ans ;

// 가중치가 저렴한 것들 우선으로 정렬되는 우선순위큐
priority_queue <pii, vector <pii>, greater<pii>> pq ;

void Dijk() {
    while ( !pq.empty() ) {
        int curNode = pq.top().second ;
        int cost = pq.top().first ;
        visited[curNode] = 1 ;
        pq.pop() ;

        // 원래 방법이 더 저렴할 경우 건너뜀
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

    cin >> v >> e >> k ;

    node.resize(v+1) ;
    visited.resize(v+1, 0) ;
    ans.resize(v+1, INF) ;

    for ( int i = 0 ; i < e ; i ++ ) {
        int a, b, c ;
        cin >> a >> b >> c ;

        node[a].push_back({b, c}) ;
    }

    ans[k] = 0 ;
    pq.push({0, k}) ; // {가중치, 도착 노드}

    Dijk() ;

    for ( int i = 1 ; i <= v ; i ++ ) {
        if ( ans[i] == INF ) cout << "INF\n" ;
        else cout << ans[i] << "\n" ;
    }

    return 0 ;
}