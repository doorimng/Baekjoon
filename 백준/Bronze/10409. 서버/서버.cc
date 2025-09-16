#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
    
    int n, T, cnt = 0 ;
    cin >> n >> T ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;
        
        T -= x ;

        if ( T >= 0 ) cnt ++ ;
        else T = -1 ;
    }

    cout << cnt ;

    return 0 ;
}