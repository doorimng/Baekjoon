#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

ll n, d = 0, g = 0 ;
vector <vector <int>> v ;
vector <int> visited ;

ll gcount(ll size) {
    if ( size < 3 ) return 0 ;

    return ((size-2) * (size-1) * size) / 6 ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ; 
    v.resize(n+1, vector <int> (0)) ;
    visited.resize(n+1, 0) ;

    for ( int i = 1 ; i < n ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        v[a].push_back(b) ;
        v[b].push_back(a) ;
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 0 ; j < v[i].size() ; j ++ ) {
            int temp = (v[i].size()-1) * (v[v[i][j]].size()-1) ;
            if ( temp >= 1 ) d += temp ;
        }
    }

    d /= 2 ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        g += gcount(v[i].size()) ;
    }

    if ( 3*g > d ) cout << 'G' ;
    else if ( 3*g == d ) cout << "DUDUDUNGA" ;
    else cout << 'D' ;

    return 0 ;
}