#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int x, l, r ;
    cin >> x >> l >> r ;

    int ans ;

    if ( abs(x-l) < abs(x-r) ) ans = l ;
    else ans = r ;

    if ( l < x && x < r ) ans = x ;

    cout << ans ;

    return 0 ;
}