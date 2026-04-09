#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    set <string> st ;
    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        st.insert(s) ;
    }

    int cnt = 0 ;
    for ( int i = 0 ; i < m ; i ++ ) {
        string s ;
        cin >> s ;

        if ( st.count(s) ) cnt ++ ;
    }

    cout << cnt ;

    return 0 ;
}