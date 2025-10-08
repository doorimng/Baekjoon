#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, cnt = 0 ;
    cin >> n ;

    for ( int i = 1 ; i <= 500 ; i ++ ) {
        for ( int j = i ; j <= 500 ; j ++ ) {
            if ( j*j - i*i == n ) cnt ++ ;
            
            if ( j*j - i*i >= n ) break ;
        }
    }

    cout << cnt ;

    return 0 ;
}