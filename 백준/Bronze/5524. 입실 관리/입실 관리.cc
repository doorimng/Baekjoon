#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        string s ;
        cin >> s ;

        for ( int i = 0 ; i < s.size() ; i ++ ) {
            if ( s[i] < 'a' ) cout << (char) (s[i] + 32) ;
            else cout << s[i] ;
        }
        cout << "\n" ;
    }

    return 0 ;
}