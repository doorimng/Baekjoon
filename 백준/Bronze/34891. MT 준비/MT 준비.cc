#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    if ( n % m ) cout << n/m + 1 ;
    else cout << n/m ; 

    return 0 ;
}