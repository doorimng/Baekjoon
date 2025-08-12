#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

int main() {
    
    cin.tie(0)->sync_with_stdio(false);

    int n ;
    cin >> n ;

    int t = 0, f = 0 ;
    
    while ( true ) {

        // cout << n << "\n" ;

        if ( n == 0 ) break ;

        // if ( n >= 15 ) {
        //     f += 3 ;
        //     n -= 15 ;
        // }

        else if ( n >= 5 ) {
            if ( n % 5 == 0 ) {
                f ++ ;
                n -= 5 ;
            }
            else {
                t ++ ;
                n -= 3 ;
            }
        }

        else if ( n >= 3 ) {
            t ++ ;
            n -= 3 ;
        }

        else {
            cout << "-1" ;
            return 0 ;
        }
    }

    cout << t + f ;

    return 0 ;
}