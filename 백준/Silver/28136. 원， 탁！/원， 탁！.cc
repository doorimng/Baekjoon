#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v(n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;
    }

    int cnt = 0 ;

    for ( int i = 1 ; i < n ; i ++ ) {
        if ( v[i] > v[i-1] ) continue ;
        else cnt ++ ;
    }

    if ( v[n-1] >= v[0] ) cnt ++ ;

    cout << cnt ;

    return 0 ;
}