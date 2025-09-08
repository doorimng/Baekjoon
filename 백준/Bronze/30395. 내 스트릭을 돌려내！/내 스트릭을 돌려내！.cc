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

    int streak = 0, Mx = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( v[i] != 0 ) {
            streak ++ ;
        }
        else {
            if ( v[i-1] == 0 ) {
                Mx = max(Mx, streak) ;
                streak = 0 ;
            }
        }
    }

    cout << max(Mx, streak) ;

    return 0 ;
}