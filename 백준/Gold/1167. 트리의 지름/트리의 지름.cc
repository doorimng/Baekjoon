#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

typedef pair <ll, ll> pll ;

int n, farNode ;
vector <vector <pll>> v ;
vector <int> leaf ;
vector <int> visited ;

ll ans = 0 ;
void DFS(int n, ll sum) {
    if ( sum > ans ) {
        ans = sum ;
        farNode = n ;
    }
    for ( pll x : v[n] ) {
        if ( !visited[x.first] ) {
            ll nextNode = x.first ;
            ll cost = x.second ;
            
            visited[nextNode] = 1 ;

            DFS(nextNode, sum+cost) ;
            
            visited[nextNode] = 0 ;
        }
    }
    return ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;
    v.resize(n+1, vector <pll> (0)) ;
    leaf.resize(n+1, 0) ;
    visited.resize(n+1, 0) ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        ll a, b, c ;
        cin >> a ;

        while ( true ) {
            cin >> b ;

            if ( b == -1 ) break ;

            cin >> c ;

            v[a].push_back({b, c}) ;
        }

        leaf[a] ++ ;
    }

    visited[1] = 1 ;
    DFS(1, 0) ;
    visited[1] = 0 ;

    visited[farNode] = 1 ;
    DFS(farNode, 0) ;
    visited[farNode] = 0 ;
    
    cout << ans ;

    // 임의의 노드를 잡아서 제일 먼 노드 찾은 후
    // 그 노드에서 제일 먼 노드와의 거리가 지름!!!
    // 전체 순회할 필요가 Xx...
    
    // ll Mx = 0 ;
    // for ( int i = 1 ; i <= n ; i ++ ) {
    //     if ( leaf[i] == 1 ) {
    //         visited[i] = 1 ;
    //         DFS(i, 0) ;
    //         Mx = max(Mx, ans) ;
    //         ans = 0 ;
    //         visited[i] = 0 ;
    //     }
    // }

    // cout << Mx ;

    return 0 ;
}