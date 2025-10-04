#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    while ( true ) {
        int n ;
        cin >> n ;

        if ( cin.fail() ) break ;

        if ( n % 6 ) cout << "N\n" ;
        else cout << "Y\n" ;
    }

    return 0 ;
}