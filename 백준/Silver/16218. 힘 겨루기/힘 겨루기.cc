#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, k, check = 0 ;
    cin >> n >> k ;

    int Junnie = 0, Sub107 = 0 ; // 각자 받은 힘

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        Junnie += b ;
        Sub107 += a ;

        if ( !check ) {
            if ( Sub107 >= k || Sub107 - Junnie >= 50 ) check = 1 ;
            else if ( Junnie >= k ) check = -1 ; 

            Sub107 += a/2 ;

            if ( !check ) {    
                if ( Sub107 >= k || Sub107 - Junnie >= 50 ) check = 1 ;
                if ( Junnie >= k ) check = -1 ; 
            }

            Sub107 -= a/2 ;
        }
    }

    cout << check ;

    return 0 ;
}