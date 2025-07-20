#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    double a, b ;
    cin >> a >> b ;

    if ( a/100 * (100-b) >= 100 ) cout << 0 ;
    else cout << 1 ;

    return 0 ;
}