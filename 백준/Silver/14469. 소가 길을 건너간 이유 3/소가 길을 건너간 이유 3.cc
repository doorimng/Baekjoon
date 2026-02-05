#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;
    
    vector <vector <int>> v ;

    while ( t -- ) {
        int a, b ;
        cin >> a >> b ;

        v.push_back({a, b}) ;
    }

    sort(v.begin(), v.end()) ;

    ll ans = 0 ;

    for ( int i = 0 ; i < v.size() ; i ++ ) {
        if ( ans >= v[i][0] ) ans += v[i][1] ;
        else ans = v[i][0] + v[i][1] ;
    }

    cout << ans ;

    return 0 ;
}