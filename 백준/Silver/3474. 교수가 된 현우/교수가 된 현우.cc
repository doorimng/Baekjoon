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
        ll n, cnt2 = 0, cnt5= 0 ;
        cin >> n ;

        for ( int i = 2 ; i <= n ; i *= 2 ) cnt2 += n / i ;
        for ( int i = 5 ; i <= n ; i *= 5 ) cnt5 += n / i ;

        cout << min(cnt2, cnt5) << "\n" ;
    }

    return 0 ;
}