#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    double n, kangho, sum = 0 ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        if ( i == 0 ) kangho = x ;

        sum += x ;
    }

    double j, c ;
    cin >> j >> c ;

    cout.precision(10) ;
    cout << kangho + (kangho * j * c) / sum ;

    return 0 ;
}