#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int a, b, c, Mx = -1 ;
    cin >> a >> b >> c ;

    vector <int> v (a+b+c+1, 0) ;

    for ( int i = 1 ; i <= a ; i ++ ) {
        for ( int j = 1 ; j <= b ; j ++ ) {
            for ( int k = 1 ; k <= c ; k ++ ) {
                v[i+j+k] ++ ;
                Mx = max(Mx, v[i+j+k]) ;
            }
        }
    }

    for ( int i = 2 ; i <= a+b+c ; i ++ ) {
        if ( v[i] == Mx ) {
            cout << i ;
            return 0 ;
        }
    }

    return 0 ;
}