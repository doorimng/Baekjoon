// 10828

#include <iostream>
#include <stack>
#include <string>

using namespace std ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        string s ;
        cin >> s ;

        stack <char> st ;

        int check = 1 ;
        for ( int i = 0 ; i < s.size() ; i ++ ) {
            if ( s[i] == '(' ) st.push(s[i]) ;
            else {
                if ( st.empty() ) check = 0 ;
                else if ( st.top() == '(' ) st.pop() ;
            }
        }
        if ( !st.empty() ) check = 0 ; 

        cout << ((check) ? "YES\n" : "NO\n") ;
    }

    return 0 ;
}
