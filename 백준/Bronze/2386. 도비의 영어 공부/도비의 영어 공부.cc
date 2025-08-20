#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    while ( true ) {
        string s ;
        getline(cin, s) ;

        if ( s == "#" ) break ;

        int cnt = 0 ;
        for ( int i = 2 ; i < s.size() ; i ++ ) {
            if ( s[i] == s[0] || s[i] + ('a'-'A') == s[0] ) cnt ++ ;
        }

        cout << s[0] << " " << cnt << "\n" ;
    }

    return 0 ;
}