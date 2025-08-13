#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

	ll n, m, a, k ;
	cin >> n >> m >> a >> k ;

	if ( (a-k) / n ) cout << n ;
	else cout << (a-k)+1 ;

	cout << " " ;

	if ( (a-k) % m ) cout << (a-k) / m + 2 ;
	else cout << (a-k) / m + 1 ;
	
    return 0 ;
}