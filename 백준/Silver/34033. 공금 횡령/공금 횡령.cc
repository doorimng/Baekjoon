#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int n, m, cnt = 0 ;
    cin >> n >> m ;

    map <string, double> mp ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string a ;
        double b ;
        cin >> a >> b ;

        mp[a] = b ;
    }

    for ( int i = 0 ; i < m ; i ++ ) {
        string c ;
        double d ;
        cin >> c >> d ;

        if ( mp[c] / 100 * 105 < d ) cnt ++ ;
    }

    cout << cnt ;

    return 0 ;
}