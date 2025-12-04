#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    ll x = 1, y = 1 ;

    while ( -- n ) {
        ll temp = x ;
        x = y ;
        y += temp ; 
    }

    cout << 2*(x+y) ;

    return 0 ;
}