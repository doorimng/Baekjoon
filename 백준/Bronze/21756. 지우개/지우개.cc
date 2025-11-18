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
        v[i] = i+1 ;
    }

    while ( true ) {
        int size = v.size() ;

        if ( size == 1 ) break ;

        for ( int i = 0 ; i < size ; i += 2 ) v[i] = -1 ;

        for ( int i = 0 ; i < v.size() ; i ++ ) {
            if ( v[i] == -1 ) v.erase(v.begin()+i) ;
        }
    }

    cout << v[0] ;

    return 0 ;
}