#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        int n, cnt = 0 ;
        cin >> n ;

        vector <int> v (n, 0) ;
        for ( int i = 0 ; i < n ; i ++ ) {
            cin >> v[i] ;
        }

        for ( int i = n-1 ; i != -1 ; i -- ) {
            for ( int j = 0 ; j < i ; j ++ ) {
                if ( v[j] > v[j+1] ) {
                    int temp = v[j+1] ;
                    v[j+1] = v[j] ;
                    v[j] = temp ;
                    cnt ++ ;
                }
            }
        }

        cout << cnt << "\n" ;
    }
    
    return 0 ;
}