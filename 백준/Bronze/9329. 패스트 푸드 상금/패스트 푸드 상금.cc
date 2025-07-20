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

        vector <vector <int>> v (n) ;
        vector <int> sticker (m+1, 0) ;

        for ( int i = 0 ; i < n ; i ++ ) {
            int k ;
            cin >> k ;

            for ( int j = 0 ; j <= k ; j ++ ) {
                int x ;
                cin >> x ;

                v[i].push_back(x) ;
            }
        }

        for ( int i = 1 ; i <= m ; i ++ ) {
            int x ;
            cin >> x ;

            sticker[i] = x ;
        }

        int ans = 0 ;

        for ( int i = 0 ; i < n ; i ++ ) {
            int cnt = INF ;
            for ( int j = 0 ; j < v[i].size()-1 ; j ++ ) {
                cnt = min(cnt, sticker[v[i][j]]) ;
            }
            ans += cnt * v[i][v[i].size()-1] ;
        }
        cout << ans << "\n" ;
    }
    return 0 ;
}