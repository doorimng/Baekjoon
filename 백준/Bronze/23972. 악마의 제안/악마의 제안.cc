#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll k, n ;
    cin >> k >> n ;

    if ( n == 1 ) cout << -1 ;

    else {
        if ( (k * n) % (n-1) ) cout << (k*n) / (n-1) + 1 ;
        else cout << (k*n) / (n-1) ; 
    }

    return 0 ;
}