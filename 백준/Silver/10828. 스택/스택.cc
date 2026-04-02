#include <iostream>
#include <stack>
#include <string>

using namespace std ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    stack <int> st ;
    while ( n -- ) {
        string s ;
        cin >> s ;

        if ( s == "push" ) {
            int x ;
            cin >> x ;

            st.push(x) ;
        }
        if ( s == "pop" ) {
            if ( !st.empty() ) {
                cout << st.top() << "\n" ;
                st.pop() ;
            }
            else cout << -1 << "\n" ;
        }
        if ( s == "size" ) cout << st.size() << "\n" ;
        if ( s == "empty" )  cout << st.empty() << "\n" ;
        if ( s == "top" ) {
            if ( !st.empty() ) cout << st.top() << "\n" ;
            else cout << -1 << "\n" ;
        }
    }

    return 0 ;
}
