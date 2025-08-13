#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

	ll n ;
	string s ;
	cin >> n >> s ;

	map <char, ll> mp ;
	
	for ( int i = 0 ; i < n ; i ++ ) {
		mp[s[i]] ++ ;
	}

	ll ans = 1 ;
	for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
		ans = ans * it->second % 1000000007 ;
	}

	if ( mp.size() != 4 ) cout << 0 ;
	else cout << ans ;

    return 0 ;
}