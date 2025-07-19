#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    map <int, int> mp ;
    for ( int i = 1 ; i <= 4 ; i ++ ) {
        int x ;
        cin >> x ;

        mp[x] = i ;
    }

    int x, y, r ;
    cin >> x >> y >> r ;
    
    cout << mp[x] ; 

    return 0 ;
}