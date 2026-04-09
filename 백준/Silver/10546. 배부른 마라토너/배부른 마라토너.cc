#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    multiset <string> st ;
    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        st.insert(s) ;
    }

    for ( int i = 1 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        st.erase(st.lower_bound(s)) ;
    }

    cout << *st.begin() ;

    return 0 ;
}