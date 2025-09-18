#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll a =  3000000000000000000 ;
    ll aa = (ll) sqrt(a) + 2 ;
    
    // // 1 (1)
    // // 2-7 (5) 
    // // 8-19 (11)
    // // 20-37 (17)
    // // 38-61 (23)

    ll n ;
    cin >> n ;

    ll st = 2, ed = aa ;

    if ( n == 1 ) {
        cout << 1 ;
        return 0 ;
    }
    else if ( n < 8 ) {
        cout << 2 ;
        return 0 ;
    }

    while ( st < ed ) {
        ll mid = (st + ed) / 2 ;

        if ( mid * (mid+1) / 2 > (n-2) / 6 ) ed = mid ;
        else st = mid + 1 ;
    }

    cout << st + 1 ;

    return 0 ;
}