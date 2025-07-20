#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <ll> v (10000001) ;
    v[1] = 5 ;

    for ( int i = 2 ; i <= n ; i ++ ) {
        v[i] = v[i-1] + (i+1)*2+(i-1) ;
    }

    cout << v[n] % 45678 ;
    return 0 ;
}