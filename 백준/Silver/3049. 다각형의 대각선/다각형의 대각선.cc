#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    if ( n == 3 ) cout << 0 ;
    else {
        cout << (n * (n-1) * (n-2) * (n-3)) / 24 ;
    }

    return 0 ;
}