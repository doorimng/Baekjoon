#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;
        
        v.push_back(x) ;
    }

    int gap = v[1] - v[0] ;

    for ( int i = 2 ; i < n ; i ++ ) {
        gap = __gcd(gap, v[i] - v[i-1]) ;
    }

    int cnt = 0 ;
    for ( int i = 1 ; i < n ; i ++ ) {
        cnt += (v[i] - v[i-1]) / gap - 1 ; 
    }

    cout << cnt ;

    return 0 ;
}