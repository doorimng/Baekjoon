#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int a, b, c, n ;
vector <vector <vector <int>>> visited ;
vector <int> v ;

struct info {
    int a ;
    int b ;
    int c ;
} ;

queue <info> q ;
void BFS() {
    while ( !q.empty() ) {
        int aa = q.front().a ;
        int bb = q.front().b ;
        int cc = q.front().c ;
        q.pop() ;

        if ( aa == 0 ) v[cc] = 1 ;

        int temp = min(a-aa, cc) ;
        if ( !visited[aa+temp][bb][cc-temp] ) {
            visited[aa+temp][bb][cc-temp] = 1 ;
            q.push({aa+temp, bb, cc-temp}) ;
        }

        temp = min(b-bb, cc) ;
        if ( !visited[aa][bb+temp][cc-temp] ) {
            visited[aa][bb+temp][cc-temp] = 1 ;
            q.push({aa, bb+temp, cc-temp}) ;
        }

        temp = min(aa, c-cc) ;
        if ( !visited[aa-temp][bb][cc+temp] ) {
            visited[aa-temp][bb][cc+temp] = 1 ;
            q.push({aa-temp, bb, cc+temp}) ;
        }

        temp = min(bb, c-cc) ;
        if ( !visited[aa][bb-temp][cc+temp] ) {
            visited[aa][bb-temp][cc+temp] = 1 ;
            q.push({aa, bb-temp, cc+temp}) ;
        }

        temp = min(aa, b-bb) ;
        if ( !visited[aa-temp][bb+temp][cc] ) {
            visited[aa-temp][bb+temp][cc] = 1 ;
            q.push({aa-temp, bb+temp, cc}) ;
        }

        temp = min(bb, a-aa) ;
        if ( !visited[aa+temp][bb-temp][cc] ) {
            visited[aa+temp][bb-temp][cc] = 1 ;
            q.push({aa+temp, bb-temp, cc}) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> a >> b >> c ;
    n = max(a, max(b, c)) ;

    visited.resize(n+1, vector <vector <int>> (n+1, vector <int> (n+1, 0))) ;
    v.resize(n+1, 0) ;

    visited[0][0][c] = 1 ;

    q.push({0, 0, c}) ; 
    BFS() ;

    for ( int i = 0 ; i <= n ; i ++ ) {
        if ( v[i] ) cout << i << " " ;
    }

    return 0 ;
}