#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    // cin.tie(0)->sync_with_stdio(false) ;
    
    double n, Mx = 0.0 ;
    cin >> n ;

    vector <double> v (n+1, 1.0) ;
    
    for ( int i = 1 ; i <= n ; i ++ ) {
        double d ;
        cin >> d ;

        if ( i > 1 ) v[i] = max(d, v[i-1] * d)  ; 
        else v[i] = d ;

        Mx = max(Mx, v[i]) ;
    }
    
    printf("%.3lf", Mx) ;

    return 0 ;
}