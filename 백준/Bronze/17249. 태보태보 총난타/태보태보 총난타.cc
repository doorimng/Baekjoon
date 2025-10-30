#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s ;
    cin >> s ;

    int cnt = 0 ;
    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( s[i] == '@' ) cnt ++ ;
        if ( s[i] == ')' ) {
            cout << cnt << " " ;
            cnt = 0 ;
        }
    }
    
    cout << cnt ;

    return 0 ;
}