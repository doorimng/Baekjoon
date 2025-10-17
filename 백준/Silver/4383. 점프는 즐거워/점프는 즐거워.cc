#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    while ( true ) {
        int n ;
        cin >> n ;

        if ( cin.eof() ) break ;

        int jumper[n] = {0, } ;

        int cur ;
        cin >> cur ;

        for ( int i = 1 ; i < n ; i ++ ) {
            int next ;
            cin >> next ;

            jumper[abs(next - cur)] = 1 ;
            cur = next ;
        }

        int check = 1 ;
        for ( int i = 1 ; i < n ; i ++ ) {
            if ( !jumper[i] ) {
                check = 0 ;
                break ;
            }
        }

        cout << (check ? "Jolly\n" : "Not jolly\n") ;
    }

    return 0 ;
}