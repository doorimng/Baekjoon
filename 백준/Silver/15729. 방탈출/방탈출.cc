#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;
    
    vector <int> v ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        v.push_back(x) ;
    }

    int cnt = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( v[i] ) {
            cnt ++ ;
            v[i] = 0 ;
            if ( i+1 < n ) v[i+1] = !v[i+1] ;
            if ( i+2 < n ) v[i+2] = !v[i+2] ;
        }
    }

    cout << cnt ;

    return 0 ;
}