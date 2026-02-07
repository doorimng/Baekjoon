#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, check = 1 ;
    cin >> n ;

    vector <int> v (n, 0) ;
    stack <pii> st ;

    for ( int i = 0  ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        if ( st.empty() ) {
            if ( x != 1 ) check = false ;
            st.push({x, i}) ;
        }
        else {
            if ( x == 1 ) {
                st.pop() ;
                st.push({x, i}) ;
            }
            else if ( x == st.top().first ) {
                st.pop() ;
                if ( st.empty() ) check = false ;
                else v[st.top().second] ++ ;
                st.push({x, i}) ;
            }
            else if ( x == st.top().first+1 ) {
                v[st.top().second] ++ ;
                st.push({x, i}) ;
            }
            else if ( x == st.top().first-1 ) {
                st.pop() ;
                st.pop() ;
                if ( st.empty() ) check = false ;
                else v[st.top().second] ++ ;
                st.push({x, i}) ;
            }
            else {
                check = false ;
            }
        }
    }

    if ( check ) {
        for ( int i = 0 ; i < n ; i ++ ) {
            cout << v[i] << "\n" ;
        }
    }
    else cout << -1 ;

    return 0 ;
}