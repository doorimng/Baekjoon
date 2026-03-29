#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, k ;
vector <vector <int>> v ;
vector <int> visited ;

pii Mx = {0, 0} ;

queue <int> q ;
void BFS() {
    while ( !q.empty() ) {
        int temp = q.front() ;
        q.pop() ;

        for ( int x : v[temp] ) {
            if ( visited[x] != -1 ) continue ;

            visited[x] = visited[temp] + 1 ;
            if ( visited[x] > Mx.second ) Mx = {x, visited[x]} ; 
            q.push(x) ;
        }
    }
}

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> k ;
    v.resize(n+1, vector <int> (0)) ;
    visited.resize(n+1, -1) ;

    for ( int i = 0 ; i < k ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        v[a].push_back(b) ;
        v[b].push_back(a) ;
    }

    visited[1] = 0 ;
    q.push(1) ;
    BFS() ;

    fill(visited.begin(), visited.end(), -1) ;

    visited[Mx.first] = 0 ;
    q.push(Mx.first) ;
    BFS() ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( visited[i] >= 7 || visited[i] == -1 ) {
            cout << "Big World!" ;
            return 0 ;
        }
    }

    cout << "Small World!" ;

    return 0 ;
}