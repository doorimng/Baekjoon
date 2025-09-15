#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
    
    int n, ans = 0 ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        if ( x % 2 ) ans ++ ;
    }

    cout << ans ;

    return 0 ;
}