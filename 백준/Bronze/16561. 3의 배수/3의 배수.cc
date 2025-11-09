#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, cnt = 0 ;
    cin >> n ;

    for ( int i = 3 ; i <= n ; i += 3 ) {
        for ( int j = 3 ; i+j <= n ; j += 3 ) {
            for ( int k = 3 ; i+j+k <= n ; k += 3 ) {
                if ( i + j + k == n ) cnt ++ ;
            }
        }
    }

    cout << cnt ;

    return 0 ;
}