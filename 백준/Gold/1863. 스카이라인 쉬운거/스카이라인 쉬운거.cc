#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, cnt = 0 ;
    cin >> n ;

    stack <int> st ;

    for ( int i = 0 ; i <= n ; i ++ ) {
        
        int x, y  ;
        if ( i != n ) cin >> x >> y ;
        else y = 0 ;

        if ( st.empty() ) st.push(y) ;
        else {
            set <int> s ;
            while ( !st.empty() && y < st.top() ) {
                s.insert(st.top()) ;
                st.pop() ;
            }
            cnt += s.size() ;
            st.push(y) ;
        }
    }

    cout << cnt ;

    return 0 ;
}