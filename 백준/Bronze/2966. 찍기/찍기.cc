#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string adrian = "ABC", bruno = "BABC", goran = "CCAABB" ;

    int n, a = 0, b = 0, g = 0 ;
    string s ;
    cin >> n >> s ;

    for ( int i = 0 ; i < n ; i ++ ) {
        if ( s[i] == adrian[i%adrian.size()] ) a ++ ;
        if ( s[i] == bruno[i%bruno.size()] ) b ++ ;
        if ( s[i] == goran[i%goran.size()] ) g ++ ;
    }

    int Mx = max(a, max(b, g)) ;
    cout << Mx << "\n" ;

    if ( Mx == a ) cout << "Adrian\n" ;
    if ( Mx == b ) cout << "Bruno\n" ;
    if ( Mx == g ) cout << "Goran\n" ;
    
    return 0 ;
}