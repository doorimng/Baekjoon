#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF LLONG_MAX

int n, m, k, s, p, q ;

vector <int> cityInfo ; // 0: 감염 1: 위험 2: 안전 
vector <vector <int>> v ;
vector <int> visited ;
vector <ll> ans ;

queue <pii> qu ;
void BFS() {
    while ( !qu.empty() ) {
        int temp = qu.front().first ;
        int cnt = qu.front().second ;
        qu.pop() ;

        if ( cnt > s ) continue ;

        visited[temp] = 1 ;
        if ( cityInfo[temp] ) cityInfo[temp] = 1 ;

        for ( int x : v[temp] ) {
            if ( !visited[x] ) {
                qu.push({x, cnt+1}) ;
            }
        }
    }
}

priority_queue <pii, vector <pii>, greater<pii>> pq ;
void dijk() {
    while ( !pq.empty() ) {
        int cost = pq.top().first ;
        int curNode = pq.top().second ;
        visited[curNode] = 1 ;
        pq.pop() ;

        if ( ans[curNode] < cost ) continue ;

        for ( int i = 0 ; i < v[curNode].size() ; i ++ ) {
            int nextNode = v[curNode][i] ;
            int nextCost ;

            if ( cityInfo[nextNode] == 2 ) nextCost = p ;
            else if ( cityInfo[nextNode] == 1 ) nextCost = q ;
            else continue ;

            if ( visited[nextNode] ) continue ;

            if ( ans[nextNode] > nextCost + ans[curNode] ) {
                ans[nextNode] = nextCost + ans[curNode] ;
                pq.push({ans[nextNode], nextNode}) ;
            }
        }
    }
}

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m >> k >> s >> p >> q ;

    cityInfo.resize(n+1, 2) ;
    v.resize(n+1, vector <int> (0)) ;
    visited.resize(n+1, 0) ;
    ans.resize(n+1, INF) ;

    for ( int i = 0 ; i < k ; i ++ ) {
        int x ;
        cin >> x ;

        visited[x] = 1 ;
        qu.push({x, 0}) ;
        cityInfo[x] = 0 ;
    }

    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        v[a].push_back(b) ;
        v[b].push_back(a) ;
    }

    BFS() ;

    fill(visited.begin(), visited.end(), 0) ;
    pq.push({0, 1}) ;
    ans[1] = 0 ;
    dijk() ;

    cout << ans[n] - ((cityInfo[n] == 1) ? q : p) ;

	return 0;
}