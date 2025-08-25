#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s ;
    cin >> s ;

    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( s[i] != 'X' ) continue ;

        if ( s.substr(i, 4) == "XXXX" ) s = s.substr(0, i) + "AAAA" + s.substr(i+4) ;
        else if ( s.substr(i, 2) == "XX" ) s = s.substr(0, i) + "BB" + s.substr(i+2) ;
    }

    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( s[i] == 'X' ) {
            cout << -1 ;
            return 0 ;
        }
    }

    cout << s ;
    
    return 0 ;
}