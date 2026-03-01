#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;
    
    map <string, int> mp ;
    for ( int i = 0 ; i < n ; i ++ ) {
        string a, b ;
        cin >> a >> b ;

        if ( b == "enter" ) mp[a] = 1 ;
        else mp[a] = 0 ;
    }

    for ( auto it = --mp.end() ; it != --mp.begin() ; it -- ) {
        if ( it->second ) cout << it->first << "\n" ;
    }

    return 0 ;
}