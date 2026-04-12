#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    cout << fixed ;
    cout.precision(3) ;

    int times = 0 ;
    while ( true ) {
        times ++ ;
        double a, b, c ;
        cin >> a >> b >> c ;

        if ( a == 0 && b == 0 && c == 0 ) break ;

        cout << "Triangle #" << times << "\n" ;

        if ( c == -1 ) {
            cout << "c = " << sqrt(a*a + b*b) << "\n\n" ;
            continue ;
        }
        else if ( a == -1 ) {
            if ( c*c - b*b > 0 ) {
                cout << "a = " << sqrt(c*c - b*b) << "\n\n" ;
                continue ;
            }
        }
        else {
            if ( c*c - a*a > 0 ) {
                cout << "b = " << sqrt(c*c - a*a) << "\n\n" ;
                continue ;
            }
        }
        cout << "Impossible.\n\n" ;
    }
    
    return 0 ;
}