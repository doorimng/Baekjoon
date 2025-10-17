#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <vector <char>> v (n, vector <char> (n, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    int check = true ;
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( v[i][j] != v[j][i] ) check = false ;
        }
    }

    cout << (check ? "YES" : "NO") ;

    return 0 ;
}