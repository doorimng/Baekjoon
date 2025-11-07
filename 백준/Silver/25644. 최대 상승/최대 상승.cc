#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v (n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;
    }

    int Mn = v[0], Mx = 0 ;

    for ( int i = 1 ; i < n ; i ++ ) {
        Mx = max(Mx, v[i] - Mn) ;
        Mn = min(Mn, v[i]) ;
    }

    cout << Mx ;

    return 0 ;
}