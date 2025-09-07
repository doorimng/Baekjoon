#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int r, c, zr, zc ;
    cin >> r >> c >> zr >> zc ;

    vector <vector <char>> v (r+1, vector <char> (c+1, 0)) ;

    for ( int i = 1 ; i <= r ; i ++ ) {
        for ( int j = 1 ; j <= c ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    for ( int i = 1 ; i <= r ; i ++ ) {
        for ( int rr = 1 ; rr <= zr ; rr ++ ) {
            for ( int j = 1 ; j <= c ; j ++ ) {
                for ( int cc = 1 ; cc <= zc ; cc ++ ) {
                    cout << v[i][j] ;
                }
            }
            cout << "\n" ;
        }
    }

    return 0 ;
}