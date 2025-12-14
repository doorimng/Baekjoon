#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, cnt = 0, error = 0, l = 0, s = 0 ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        char c ;
        cin >> c ;

        if ( error ) continue ;

        if ( c <= '9' ) cnt ++ ;
        else {
            if ( c == 'L' ) l ++ ;
            if ( c == 'S' ) s ++ ;
            if ( c == 'R' ) {
                if ( l ) {
                    l -- ;
                    cnt ++ ;
                }
                else error = 1 ;
            }
            if ( c == 'K' ) {
                if ( s ) {
                    s -- ;
                    cnt ++ ;
                }
                else error = 1 ;
            }
        }
    }

    cout << cnt ;

    return 0 ;
}