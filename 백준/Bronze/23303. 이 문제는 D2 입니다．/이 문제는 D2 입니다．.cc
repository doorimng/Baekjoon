#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
    
    string s ;
    getline(cin, s) ;

    for ( int i = 0 ; i < s.size()-1 ; i ++ ) {
        if ( s[i] == 'D' || s[i] == 'd' ) {
            if ( s[i+1] == '2' ) {
                cout << "D2" ;
                return 0 ;
            }
        }
    }
    
    cout << "unrated" ;
    return 0 ;
}