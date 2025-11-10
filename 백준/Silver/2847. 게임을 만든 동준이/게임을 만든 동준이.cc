#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n, cnt = 0 ;
    cin >> n ;

    vector <ll> v (n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;
    }

    for ( int i = n-2 ; i != -1 ; i -- ) {
        while ( v[i+1] <= v[i] ) {
            v[i] -- ;
            cnt ++ ;
        }
    }

    cout << cnt ;

    return 0 ;
}