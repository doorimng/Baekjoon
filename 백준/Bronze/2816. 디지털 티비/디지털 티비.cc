#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, first_is_1 = 0 ;
    cin >> n ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        string s ;
        cin >> s ;

        if ( s == "KBS1" || s == "KBS2" ) {
            if ( first_is_1 == 0 ) {
                if ( s == "KBS1" ) first_is_1 = 1 ;
                else first_is_1 = -1 ;
            }

            for ( int j = 0 ; j < i - 1 ; j ++ ) cout << '1' ;
            for ( int j = 0 ; j < i - 1 ; j ++ ) cout << '4' ;
        }
    }

    if ( first_is_1 == 1 ) cout << '3' ;

    return 0 ;
}