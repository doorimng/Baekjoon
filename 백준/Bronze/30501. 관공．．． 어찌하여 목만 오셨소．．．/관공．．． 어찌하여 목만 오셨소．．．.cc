#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;
    string ans ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        for ( int j = 0 ; j < s.size() ; j ++ ) {
            if ( s[j] == 'S' ) ans = s ;
        }
    }

    cout << ans ;

    return 0 ;
}