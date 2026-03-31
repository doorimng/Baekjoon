#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n, k ;
    cin >> n >> k ;
    
    vector <int> coin ;
    vector <ll> v (10100, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        coin.push_back(x) ;
    }

    sort(coin.begin(), coin.end()) ;

    for ( int j = 0 ; j < coin.size() ; j ++ ) {
        v[coin[j]] ++ ;
        for ( int i = 1 ; i <= k ; i ++ ) {
            if ( i-coin[j] > 0 ) v[i] += v[i-coin[j]] ;
        }
    }

    cout << v[k] ;

    return 0 ;
}