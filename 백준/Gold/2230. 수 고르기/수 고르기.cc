#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    vector <int> v (n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;
    }

    sort(v.begin(), v.end()) ;
    
    int i = 0, j = 0, ans = INF ;
    while ( true ) {
        if ( i > j || i >= n || j >= n || ans == m ) break ;

        if ( v[j] - v[i] < m ) j ++ ;
        else {
            ans = min(ans, v[j]-v[i]) ;
            i ++ ;
        }
    }

    cout << ans ;

    return 0 ;
}