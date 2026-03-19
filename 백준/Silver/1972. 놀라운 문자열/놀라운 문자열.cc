#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    while ( true ) {
        string s ;
        cin >> s ;

        if ( s == "*" ) break ;

        int check = 1 ;
        for ( int i = 1 ; i < s.size()-1 ; i ++ ) {
            set <string> st ;
            int cnt = 0 ;
            for ( int j = 0 ; j+i < s.size() ; j ++ ) {
                char a = s[j], b = s[j+i] ;
                string temp = "" ;
                temp += a ;
                temp += b ;
                st.insert(temp) ;
                cnt ++ ;
            }

            if ( st.size() != cnt ) {
                check = 0 ;
                break ;
            }
        }
        
        if ( check ) cout << s << " is surprising.\n" ;
        else cout << s << " is NOT surprising.\n" ;
    }

    return 0 ;
}