#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, f ;
    cin >> n >> f ;

    if ( n >= 6 ) cout << "Love is open door" ;
    else {
        n -- ; f ++ ;
        while ( n -- ) {
            f %= 2 ;
            cout << f ++ << "\n" ;
        }
    }

    return 0 ;
}