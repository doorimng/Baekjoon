#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n, cnt = 0 ;
    cin >> n ;

    for ( int i = 1 ; i <= n/3 ; i ++ ) {
        for ( int j = i ; j <= (n-i)/2 ; j ++ ) {

            int k = n - (i+j) ;
            // cout << i << " " << j << " " << k << "\n" ;

            if ( i+j > k ) cnt ++ ;
        }
    }

    cout << cnt ;

    return 0 ;
}