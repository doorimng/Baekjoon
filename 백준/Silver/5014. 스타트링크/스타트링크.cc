#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int f, s, g, u, d ;
vector <int> visited ;

queue <int> q ;
void BFS() {
    while ( !q.empty() ) {
        int temp = q.front() ;
        q.pop() ;

        for ( int i : {u, -d} ) {
            int x = temp + i ;

            if ( x <= 0 || x > f ) continue ;
            if ( visited[x] ) continue ;

            visited[x] = visited[temp] + 1 ;
            q.push(x) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> f >> s >> g >> u >> d ;

    visited.resize(f+1, 0) ;

    visited[s] = 1 ;
    q.push(s) ;
    BFS() ;

    if ( visited[g] ) cout << visited[g] - 1 ;
    else cout << "use the stairs" ;

    return 0 ;
}