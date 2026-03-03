#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int n, m ;
    cin >> n >> m ;

    if ( n == 1 ) cout << 1 ;
    else if ( n == 2 ) {
        if ( m >= 7 ) cout << 4 ;
        else cout << m/2 + m%2 ;
    }
    else {
        if ( m <= 4 ) cout << m ;
        else if ( m <= 6 ) cout << 4 ;
        else cout << m-2 ;
    }

    return 0 ;
}