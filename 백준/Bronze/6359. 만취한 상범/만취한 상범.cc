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
        int n ;
        cin >> n ;

        vector <int> room (n+1, 0) ;

        for ( int i = 1 ; i <= n ; i ++ ) {
            for ( int j = i ; j <= n ; j += i ) {
                room[j] = !room[j] ;
            }
        }

        int cnt = 0 ;
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( room[i] ) cnt ++ ;
        }

        cout << cnt << "\n" ;
    }
 
    return 0 ;
}