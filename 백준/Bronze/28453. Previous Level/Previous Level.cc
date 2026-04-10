#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        if ( x >= 300 ) cout << "1 " ;
        else if ( x >= 275 ) cout << "2 " ;
        else if ( x >= 250 ) cout << "3 " ;
        else cout << "4 " ;
    }
    
    return 0 ;
}