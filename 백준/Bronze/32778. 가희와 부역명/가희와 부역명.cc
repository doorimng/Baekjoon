#include <bits/stdc++.h>

using namespace std ;
typedef unsigned long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    string s ;
    getline(cin, s) ;

    int check = 0 ;

    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( s[i] == '(' || s[i] == ')' ) {
            check = 1 ;
            cout << "\n" ;
        }
        else cout << s[i] ;
    }

    if ( check == 0 ) cout << "\n-" ;
    
    return 0 ;
}