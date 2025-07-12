#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, k, cnt = 1 ;
    cin >> n >> k ;

    vector <int> v (100001, 0) ;
    
    for ( int i = 2 ; i <= 100000 ; i ++ ) {
        if ( !v[i] ) {
            for ( int j = i ; j <= 100000 ; j += i ) {
                v[j] = i ;
            }
        }
    }

    for ( int i = 2 ; i <= n ; i ++ ) {
        if ( v[i] <= k ) cnt ++ ;
    }

    cout << cnt ;

    return 0 ;
}