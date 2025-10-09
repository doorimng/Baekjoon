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
    vector <vector <int>> visited (n, vector <int> (n, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    int a = 0, b = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int cnt = 0 ;
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( v[i][j] == 'X' ) {
                if ( cnt >= 2 ) a ++ ;
                cnt = 0 ;
            }
            else cnt ++ ;
        }   
        if ( cnt >= 2 ) a ++ ;
    }

    for ( int j = 0 ; j < n ; j ++ ) {
        int cnt = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( v[i][j] == 'X' ) {
                if ( cnt >= 2 ) b ++ ;
                cnt = 0 ;
            }
            else cnt ++ ;
        }
        if ( cnt >= 2 ) b ++ ;
    }

    cout << a << " " << b ;

    return 0 ;
}