#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    map <string, int, greater<string>> mp ;

    int n ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ ) {
        string a, b ;
        cin >> a >> b ;

        if ( b == "enter" ) mp[a] = 1 ;
        else mp.erase(a) ;
    }

    for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
        cout << it->first << "\n" ;
    }
    
    return 0 ;
}