#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s ;
    cin >> s ;

    stack <string> st ;

    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( s[i] == '(' || s[i] == '[' ) {
            string temp = "" ;
            temp += s[i] ;

            st.push(temp) ;
        }
        else {
            if ( st.empty() ) {
                cout << 0 ;
                return 0 ;
            }

            if ( s[i] == ')' ) {
                int num = 0 ;

                if ( st.top() == "(" ) num = 2 ;
                else {
                    while ( st.top() != "(" ) {
                        if ( st.top() == "]" || st.top() == "[" ) {
                            cout << "0\n" ;
                            return 0 ;
                        }

                        int temp = stoi(st.top()) ;
                        num += temp ;
    
                        st.pop() ;
                        if ( st.empty() ) {
                            cout << 0 ;
                            return 0 ;
                        }
                    }
                    num *= 2 ;
                }
                st.pop() ;
                st.push(to_string(num)) ;
            }
            if ( s[i] == ']' ) {
                int num = 0 ;

                if ( st.top() == "[" ) num = 3 ;
                else {
                    while ( st.top() != "[" ) {
                        if ( st.top() == ")" || st.top() == "(" ) {
                            cout << "0\n" ;
                            return 0 ;
                        }
                        int temp = stoi(st.top()) ;
                        num += temp ;
    
                        st.pop() ;
                        if ( st.empty() ) {
                            cout << 0 ;
                            return 0 ;
                        }
                    }
                    num *= 3 ;
                }
                st.pop() ;
                st.push(to_string(num)) ;
            }
        }
    }

    int ans = 0 ;
    while ( !st.empty() ) {
        if ( st.top() == "(" || st.top() == "[" ) {
            cout << 0 ;
            return 0 ;
        }
        ans += stoi(st.top()) ;
        // cout << st.top() << " " ;
        st.pop() ;
    }

    cout << ans ;
 
    return 0 ;
}