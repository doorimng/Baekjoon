#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, q ;
    cin >> n >> q ;

    vector <int> v (300001, 0) ;
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        char x ;
        cin >> x ;

        v[i] = x - '0' ;
    }

    for ( int i = 0 ; i < q ; i ++ ) {
        int cmd, a, b ;
        cin >> cmd ;

        if ( cmd == 1 ) {
            cin >> a ;
            v[a] = !v[a] ;
        }
        else {
            cin >> a >> b ;

            int len = b-a+1 ;

            if ( len == 1 ) cout << "NO" ;
            else if ( len == 2 ) {
                if ( v[a] == v[b] ) cout << "YES" ;
                else cout << "NO" ;
            }
            else if ( len == 3 ) {
                if ( v[a] != v[a+1] && v[a+1] != v[b] ) cout << "NO" ;
                else cout << "YES" ;
            }
            else cout << "YES" ;
            
            cout << "\n" ;
        }
    }

    return 0 ;
}