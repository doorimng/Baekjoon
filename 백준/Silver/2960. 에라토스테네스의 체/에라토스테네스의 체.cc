#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, k, cnt = 0 ;
    cin >> n >> k ;

    vector <int> v (1001, 0) ;
    v[1] = 1 ;
    
    for ( int i = 2 ; i <= n ; i ++ ) {
        if ( !v[i] ) {
            cnt ++ ;
            if ( cnt == k ) {
                cout << i ;
                return 0 ;
            }

            for ( int j = i+i ; j <= n ; j += i ) {
                if ( !v[j] ) {
                    cnt ++ ;
                    v[j] = 1 ;
    
                } 

                if ( cnt == k ) {
                    cout << j ;
                    return 0 ;
                }
            }
        }
    }
    return 0 ;
}