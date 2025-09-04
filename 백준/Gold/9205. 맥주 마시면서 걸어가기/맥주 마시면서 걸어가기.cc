#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <int>> node ;
vector <int> visited ;

void DFS(int n) {
    visited[n] = 1 ;

    for ( int x : node[n] ) {
        if ( !visited[x] ) {
            DFS(x) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        int n ;
        cin >> n ;
        
        vector <pii> v ;

        node.clear() ;
        visited.clear() ;
        node.resize(n+5) ;
        visited.resize(n+5, 0) ;
        
        int a, b ;
        cin >> a >> b ;

        v.push_back({a, b}) ;
        

        for ( int i = 0 ; i < n ; i ++ ) {
            int x, y ;
            cin >> x >> y ;

            v.push_back({x, y}) ;
        }

        int c, d ;
        cin >> c >> d ;

        v.push_back({c, d}) ;

        for ( int i = 0 ; i < v.size() ; i ++ ) {
            for ( int j = 0 ; j < v.size() ; j ++ ) {
                if ( i == j ) continue ;

                if ( abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= 1000 ) {
                    node[i].push_back(j) ;
                    node[j].push_back(i) ;
                }
            }
        }

        DFS(0) ;

        if ( visited[n+1] ) cout << "happy\n" ;
        else cout << "sad\n" ;
    }

    return 0 ;
}