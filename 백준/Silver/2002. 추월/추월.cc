#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

typedef pair <string, int> psi ;

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    map <string, int> mp ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        string s ;
        cin >> s ;

        mp[s] = i ;
    }

    int cnt = 0 ;
    vector <string> temp (n+1, "") ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        string s ;
        cin >> s ;

        temp[i] = s ;
    }

    vector <int> check (n+1, 0) ;

    for ( int i = 2 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j < i ; j ++ ) {
            if ( mp[temp[j]] > mp[temp[i]] ) check[j] = 1 ;
        }
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( check[i] ) cnt ++ ;
    }

    cout << cnt ;

	return 0;
}