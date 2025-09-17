#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
    
    int n ;
    cin >> n ;

    for ( int i = 0 ; i < 5 ; i ++ ) {
        for ( int t = 0 ; t < n ; t ++ ) {
            for ( int j = 0 ; j < 5 ; j ++ ) {
                for ( int k = 0 ; k < n ; k ++ ) {
                    if ( i == 2 || i == 4 ) {
                        cout << '@' ;
                    }
                    else {
                        if ( j == 0 || j == 4 ) cout << '@' ;
                        else cout << ' ' ;
                    }
                }
            }
            cout << "\n" ;
        }
    }

    return 0 ;
}