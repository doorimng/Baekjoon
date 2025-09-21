#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s, k, temp = "" ;
    cin >> s >> k ;

    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( '0' <= s[i] && s[i] <= '9' ) continue ;
        temp += s[i] ;
    }

    int check = 0 ;

    if ( temp.size() < k.size() ) {
        cout << 0 ;
        return 0 ;
    }

    for ( int i = 0 ; i < temp.size() - k.size() + 1 ; i ++ ) {
        if ( temp.substr(i, k.size()) == k ) check = 1 ;
    }

    cout << check ;

    return 0 ;
}