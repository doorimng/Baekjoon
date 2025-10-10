#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int c, k, p ;
    cin >> c >> k >> p ;

    ll sum = 0 ;

    for ( int i = 1 ; i <= c ; i ++ ) {
        sum += k * i + p * i * i ; 
    }

    cout << sum ;

    return 0 ;
}