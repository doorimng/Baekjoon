#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    for ( int i = 1 ; i <= t ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        cout << "Case " << i << ": " << a+b << "\n" ;
    }

    return 0 ;
}