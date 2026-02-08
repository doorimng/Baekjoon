#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    vector <int> so (100001, 0) ;
    so[0] = so[1] = 1 ;

    for ( int i = 2 ; i <= 1000 ; i ++ ) {
        if ( !so[i] ) {
            for ( int j = i+i ; j <= 100000 ; j += i ) {
                so[j] = 1 ;
            }
        }
    }

    vector <int> v (100001, 0) ;

    for ( int i = 1 ; i <= 100000 ; i ++ ) {
        int check = 0, d = 10 ;
        if ( !so[i+1] ) {
            check = 1 ;
            for ( int j = 1 ; j < to_string(i).size() ; j ++ ) {
                if ( so[(i/d) * (i%d) + 1] ) check = 0 ;
                d *= 10 ;
            }
        }
        v[i] = v[i-1] + check ;
    }

    while ( t -- ) {
        int n ; 
        cin >> n ;

        cout << v[n] << "\n" ;
    }

    return 0 ;
}