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
        ll n, c ;
        cin >> n >> c ;

        int temp = ((n % c == 0) ? 0 : 1) ;

        cout << n / c + temp << "\n" ;
    }

    return 0 ;
}