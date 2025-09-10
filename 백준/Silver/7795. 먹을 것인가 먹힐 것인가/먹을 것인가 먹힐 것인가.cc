#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        int n, m ;
        cin >> n >> m ;

        vector <int> a(n, 0), b(m, 0) ;

        for ( int i = 0 ; i < n ; i ++ ) cin >> a[i] ;
        for ( int i = 0 ; i < m ; i ++ ) cin >> b[i] ;

        sort(a.begin(), a.end()) ;
        sort(b.begin(), b.end()) ;

        int cnt = 0 ;

        for ( int i = 0 ; i < m ; i ++ ) {
            for ( int j = 0 ; j < n ; j ++ ) {
                if ( a[j] > b[i] ) {
                    cnt += n-j ;
                    break ;
                }
            }
        }
        cout << cnt << "\n" ;
    }

    return 0 ;
}