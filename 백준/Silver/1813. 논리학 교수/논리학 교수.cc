#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int n ;
    cin >> n ;

    map <int, int> mp ;
    mp[0] = 0 ;
    
    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        mp[x] ++ ;
    }

    int ans = -1 ;
    for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
        if ( it->first == it->second ) ans = it->first ;
    }

    cout << ans ;

    return 0 ;
}