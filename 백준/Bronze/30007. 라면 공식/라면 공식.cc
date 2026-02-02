#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b, x ;
        cin >> a >> b >> x ;

        cout << a*(x-1)+b << "\n" ;
    }

    return 0 ;
}