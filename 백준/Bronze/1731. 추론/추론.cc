#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    vector <ll> v ;

    while ( t -- ) {
        ll n ;
        cin >> n ;

        v.push_back(n) ;
    }

    if ( v[2] - v[1] == v[1] - v[0] ) {
        cout << v[v.size()-1] + (v[1] - v[0]) ;
    }
    else cout << v[v.size()-1] * (v[1] / v[0]) ;
	
    return 0 ;
}