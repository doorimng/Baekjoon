#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n ;
vector <vector <pii>> v ;
vector <int> visited ;
vector <int> minArray ;

pii makeSimple(pii pq) {
    int p = pq.first ;
    int q = pq.second ;
    
    int d = __gcd(p, q) ;

    while ( d != 1 ) {
        p /= d ;
        q /= d ;

        d = __gcd(p, q) ;
    }

    return {p, q} ;
}

queue <int> qu ;
void BFS() {
    while ( !qu.empty() ) {
        int temp = qu.front() ;
        qu.pop() ;

        for ( int x = 0 ; x < n ; x ++ ) {
            if ( visited[x] ) continue ;

            int p = v[temp][x].first ;
            int q = v[temp][x].second ;

            if ( !p || !q ) continue ;

            if ( visited[temp] % p ) {
                for ( int i = 0 ; i < n ; i ++ ) {
                    visited[i] *= p ;
                }
            }

            int pp = visited[temp] / p ;

            visited[x] = pp*q ;
            qu.push(x) ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;

    v.resize(n+1, vector <pii> (n+1, {0, 0})) ;
    visited.resize(n+1, 0) ;
    minArray.resize(n+1, 1) ;

    for ( int i = 1 ; i < n ; i ++ ) {
        int a, b, p, q ;
        cin >> a >> b >> p >> q ;

        pii temp = makeSimple({p, q}) ;
        p = temp.first ;
        q = temp.second ;

        v[a][b] = {p, q} ;
        minArray[a] = minArray[a]*p / __gcd(minArray[a], p) ;
        
        v[b][a] = {q, p} ;
        minArray[b] = minArray[b]*q / __gcd(minArray[b], q) ;
    }
    
    visited[0] = minArray[0] ;
    qu.push(0) ;
    BFS() ;
    
    int d = visited[0] ;
    for ( int i = 1 ; i < n ; i ++ ) {
        d = __gcd(d, visited[i]) ;
    }
    
    for ( int i = 0 ; i < n ; i ++ ) {
        cout << visited[i]/d << " " ;
    }
    
    return 0 ;
}