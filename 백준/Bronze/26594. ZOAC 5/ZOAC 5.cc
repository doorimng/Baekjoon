#include <iostream>
#include <string>
#include <vector>
using namespace std ; 

int main() {

    vector <int> v (26, 0) ;
    
    string s ;
    cin >> s ;

    for ( int i = 0 ; i < s.size() ; i ++ ) {
        char c = s[i] ;

        v[c-'A'] ++ ;
    }

    for ( int i = 0 ; i < 26 ; i ++ ) {
        if ( v[i] ) {
            cout << v[i] ;
            break ;
        }
    }

    return 0 ;
}