#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
    
    int t ;
    cin >> t ;

    map <int, int> mp ;

    for ( int i = 1 ; i <= 100000 ; i ++ ) {
        mp[i*i] = 1 ;
    }

    while ( t -- ) {
        int n ;
        cin >> n ;

        cout << mp[n] << "\n" ;
    }

    return 0 ;
}