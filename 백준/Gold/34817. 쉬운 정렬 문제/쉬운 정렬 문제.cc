#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, k, Mn = INF, check = 1 ;
    cin >> n >> k ;

    vector <int> v (n, 0) ;
    vector <int> temp (n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;
        temp[i] = v[i] ;
    }
    
    sort(temp.begin(), temp.end()) ;
    
    if ( k == 0 ) {
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( v[i] != temp[i] ) check = 0 ;
        }
    }
    else {
        for ( int i = n-1 ; i != 0 ; i -- ) {
            int x = v[i] ;
    
            if ( Mn == INF ) Mn = x ;
            else {
                if ( x - Mn > k ) check = 0 ;
                Mn = min(x, Mn) ;
            }
        }
    }
    
    cout << (check ? "YES" : "NO") ;

    return 0 ;
}