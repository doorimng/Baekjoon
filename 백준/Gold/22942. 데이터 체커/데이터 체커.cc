#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct info {
    int x ;
    int indx ;
    int is_close ; // 0이면 open 1이면 close 
} ;

struct cmp {
    bool operator()(info a, info b) {
        return a.x < b.x ;
    }
} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <info> v ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x, r ;
        cin >> x >> r ;

        v.push_back({x-r, i, 0}) ;
        v.push_back({x+r, i, 1}) ;
    }

    sort(v.begin(), v.end(), cmp()) ;

    stack <info> st ;

    for ( int i = 0 ; i < v.size() ; i ++ ) {
        info cur = v[i] ;

        if ( !cur.is_close ) { // open이면
            st.push(cur) ;
        }
        else {
            if ( st.empty() ) {
                cout << "NO" ;
                return 0 ;
            }

            if ( cur.is_close && st.top().indx == cur.indx ) {
                st.pop() ;
            }
            else {
                cout << "NO" ;
                return 0 ;
            }
        }
    }

    cout << "YES" ;
    return 0 ;
}