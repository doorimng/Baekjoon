#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    int btn[101] = {0, } ;
    for ( int i = 1 ; i <= n ; i ++ ) cin >> btn[i] ;
    
    int student ;
    cin >> student ;

    for ( int i = 0 ; i < student ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        if ( a == 1 ) {
            for ( int j = b ; j <= n ; j +=b ) btn[j] = !btn[j] ;
        }
        else {
            btn[b] = !btn[b] ;
            int gap = 1 ;
            while ( true ) {
                if ( b - gap <= 0 || b + gap > n ) break ;

                if ( btn[b-gap] != btn[b+gap] ) break ;

                btn[b-gap] = btn[b+gap] = !btn[b-gap] ;

                gap ++ ;
            }
        }
    }


    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( i != 1 && i % 20 == 1 ) cout << "\n" ;
        cout << btn[i] << " " ;
    }

    return 0 ;
}