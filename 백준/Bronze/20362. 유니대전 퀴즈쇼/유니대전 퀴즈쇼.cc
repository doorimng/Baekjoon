#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n, check = 0 ;
    string s ;
    cin >> n >> s ;

    map <string, int> mp ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string a, b ;
        cin >> a >> b ;

        if ( check ) continue ;

        mp[b] ++ ;
        if ( a == s ) cout << mp[b]-1 ;
    }

    return 0 ;
}