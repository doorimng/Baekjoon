#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, k, b ;
    cin >> n >> k >> b ;

    vector <int> v (n+1, 1) ;

    v[0] = 0 ;
    for ( int i = 0 ; i < b ; i ++ ) {
        int x ;
        cin >> x ;

        v[x] = 0 ;
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        v[i] += v[i-1] ;
    }

    int ans = INF ;
    for ( int i = 0 ; i+k <= n ; i ++ ) {
        ans = min(ans, k - (v[i+k] - v[i])) ;
    }   

    cout << ans ;

    return 0 ;
}