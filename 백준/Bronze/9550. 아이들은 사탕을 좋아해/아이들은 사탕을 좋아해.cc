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
        int n, k, cnt = 0 ;
        cin >> n >> k ;

        for ( int i = 0 ; i < n ; i ++ ) {
            int x ;
            cin >> x ;

            cnt += x / k ;
        }

        cout << cnt << "\n" ;
    }

    return 0 ;
}