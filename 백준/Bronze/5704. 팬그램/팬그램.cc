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

        int alpha[26] = {0, } ;

        if ( s == "*" ) break ;

        for ( int i = 0 ; i < s.size() ; i ++ ) {
            if ( s[i] == ' ' ) continue ;
            alpha[s[i] - 'a'] = 1 ;
        }

        int check = true ;
        for ( int i = 0 ; i < 26 ; i ++ ) {
            if ( alpha[i] == 0 ) {
                check = false ;
                break ;
            }
        }

        check ? (cout << "Y\n") : (cout << "N\n") ;
    }
    
    return 0 ;
}
