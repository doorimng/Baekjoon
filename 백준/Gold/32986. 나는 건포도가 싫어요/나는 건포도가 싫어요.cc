#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
   
    int x, y, z ;
    cin >> x >> y >> z ;

    int temp = min(x, min(y, z)), ans = 0 ;

    if ( temp > 2 ) {
        ans = temp / 2 ;
        if ( temp % 2 == 0 ) ans -- ; 
    }

    if ( x == 3 && y == 3 && z == 3 ) ans = 0 ;
    cout << ans ;

    return 0 ;
}