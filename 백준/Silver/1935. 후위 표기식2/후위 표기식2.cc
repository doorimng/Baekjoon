// 10828

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std ;

int main() {

    // cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    string s ;
    cin >> s ;

    vector <int> alpha (26) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> alpha[i] ;
    }

    stack <double> st ;    
    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( 'A' <= s[i] && s[i] <= 'Z' ) {
            st.push(alpha[s[i]-'A']) ;
        }
        else {
            double a = st.top() ;
            st.pop() ;
            double b = st.top() ;
            st.pop() ;

            if ( s[i] == '*' ) st.push(b*a) ;
            if ( s[i] == '+' ) st.push(b+a) ;
            if ( s[i] == '/' ) st.push(b/a) ;
            if ( s[i] == '-' ) st.push(b-a) ;
        }
    }

    printf("%.2f", st.top()) ;

    return 0 ;
}
