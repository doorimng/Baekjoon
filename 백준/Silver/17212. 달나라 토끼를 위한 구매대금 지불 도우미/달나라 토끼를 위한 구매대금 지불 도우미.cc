#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v (100001, INF) ;

    int coins[4] = {1, 2, 5, 7} ;

    v[0] = 0 ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 0 ; j < 4 ; j ++ ) {
            if ( i-coins[j] < 0 || v[i-coins[j]] == INF ) continue ;
            v[i] = min(v[i-coins[j]]+1, v[i]) ;
        }
    }

    cout << v[n] ;

    return 0 ;
}