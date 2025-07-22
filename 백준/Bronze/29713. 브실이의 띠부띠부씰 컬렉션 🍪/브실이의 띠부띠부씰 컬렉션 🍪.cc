#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    map <char, int> mp ;

    for ( int i = 0 ; i < n ; i ++ ) {
        char c ;
        cin >> c ;

        mp[c] ++ ;
    }

    int cnt = 0 ;
    string ans = "BRONZESILVER" ;

    while ( true ) {
        for ( char x : ans ) {
            mp[x] -- ;

            if ( mp[x] < 0 ) {
                cout << cnt ;
                return 0 ;
            }
        }
        cnt ++ ;
    }

    return 0 ;
}