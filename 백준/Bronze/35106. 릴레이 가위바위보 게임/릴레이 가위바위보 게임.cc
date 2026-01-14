#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v (4, 0) ;
    
    for ( int i = 1 ; i <= 3*n ; i ++ ) {
        int x ;
        cin >> x ;

        v[x] ++ ;
    }

    int Mn, Mx ;
    for ( int i = 1 ; i <= 3 ; i ++ ) {
        if ( v[i] == n-1 ) Mn = i ;
        if ( v[i] == n+1 ) Mx = i ;
    }

    cout << Mn << " " << Mx ;

    return 0 ;
}