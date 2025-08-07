#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
	
	string s ;
	cin >> s ;

	vector <int> t ;

	int is_alpsoo = true ;
	for ( int i = 1 ; i < s.size() ; i ++ ) {
		t.push_back(s[i]-s[i-1]) ;
	}

	if ( t[0] <= 0 || t[t.size()-1] >= 0 ) is_alpsoo = false ;
	for ( int i = 1 ; i < t.size() ; i ++ ) {
		if ( t[i] == 0 ) is_alpsoo = false ;
		if ( t[i] * t[i-1] > 0 && t[i] != t[i-1] ) is_alpsoo = false ;
	}

	// for ( int i = 0 ; i < t.size() ; i ++ ) cout << t[i] << " " ;
	// cout << "\n" ;
	// cout << is_alpsoo ;

	if ( is_alpsoo ) cout << "ALPSOO" ;
	else cout << "NON ALPSOO" ;

    return 0 ;
}