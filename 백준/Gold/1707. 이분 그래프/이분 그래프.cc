#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int check = 1 ;
vector <vector <int>> v ;
vector <int> visited ;

queue <int> q ;
void BFS() {
    while ( !q.empty() ) {
        int temp = q.front() ;
        q.pop() ;

        for ( int x : v[temp] ) {
            if ( !visited[x] ) {
                visited[x] = -visited[temp] ;
                q.push(x) ;
            }
            else if ( visited[x] == visited[temp] ) check = false ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int k ;
    cin >> k ;

    while ( k -- ) {
        int n, e ;
        cin >> n >> e ;

        v.clear() ;
        visited.clear() ;

        v.resize(n+1, vector <int> (0)) ;
        visited.resize(n+1, 0) ;

        for ( int i = 0 ; i < e ; i ++ ) {
            int a, b ;
            cin >> a >> b ;

            v[a].push_back(b) ;
            v[b].push_back(a) ;
        }

        check = 1 ;
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( !visited[i] ) {
                q.push(i) ;
                visited[i] = 1 ;
                BFS() ;
            }

            if ( !check ) break ;
        }

        if ( check ) cout << "YES\n" ;
        else cout << "NO\n" ;
    }

    return 0 ;
}