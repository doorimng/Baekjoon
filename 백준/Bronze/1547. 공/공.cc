#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int m, ball = 1 ;
    cin >> m ;

    for ( int i = 0 ; i < m ; i ++ ) {
        int x, y ;
        cin >> x >> y ;

        if ( x == ball || y == ball ) {
            if ( x == ball ) ball = y ;
            else ball = x ; 
        }
    }

    cout << ball ;
	
    return 0 ;
}