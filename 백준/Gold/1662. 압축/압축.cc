#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s, temp = "" ;
	cin >> s ;

	stack <pair <string, int>> st ;

	for ( int i = 0 ; i < s.size() ; i ++ ) {
		if ( s[i] != ')' ) st.push({temp + s[i], 0}) ;	
		else {
			int cnt = 0 ;
			while ( st.top().first != "(" ) {
				if ( st.top().second ) cnt += stoi(st.top().first) ;
				else cnt ++ ;
				st.pop() ;
			}
			st.pop() ;

			int st_top = stoi(st.top().first) ;
			st.pop() ;
			st.push({to_string(st_top*cnt), 1}) ;
		}
	}

	int ans = 0 ;
	while ( !st.empty() ) {
		if ( st.top().second ) ans += stoi(st.top().first) ;
		else ans ++ ;

		st.pop() ;
	}

	cout << ans ;

    return 0 ;
}