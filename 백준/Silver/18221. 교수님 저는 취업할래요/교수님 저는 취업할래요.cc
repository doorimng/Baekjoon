#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <vector <int>> v (n, vector <int> (n, 0)) ;

    pii s, p ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> v[i][j] ;

            if ( v[i][j] == 2 ) s = {i, j} ;
            if ( v[i][j] == 5 ) p = {i, j} ;
        }
    }

    if ( sqrt((s.first-p.first)*(s.first-p.first) + (s.second-p.second)*(s.second-p.second)) < 5 ) {
        cout << 0 ;
        return 0 ;
    }

    int cnt = 0 ;
    for ( int i = min(s.first, p.first) ; i <= max(s.first, p.first) ; i ++ ) {
        for ( int j = min(s.second, p.second) ; j <= max(s.second, p.second) ; j ++ ) {
            if ( v[i][j] == 1 ) cnt ++ ;
        }
    }

    if ( cnt >= 3 ) cout << 1 ;
    else cout << 0 ;

    return 0 ;
}