#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    string str ;
    cin >> str ;

    int m = 0, o = 0, b = 0, i = 0, s = 0 ;

    for ( int j = 0 ; j < str.size() ; j ++ ) {
        if ( str[j] - 'M' == 0 ) m = 1 ;
        if ( str[j] - 'O' == 0 ) o = 1 ;
        if ( str[j] - 'B' == 0 ) b = 1 ;
        if ( str[j] - 'I' == 0 ) i = 1 ;
        if ( str[j] - 'S' == 0 ) s = 1 ;
    }

    if ( m+o+b+i+s == 5 ) cout << "YES" ;
    else cout << "NO" ;

    return 0 ;
}