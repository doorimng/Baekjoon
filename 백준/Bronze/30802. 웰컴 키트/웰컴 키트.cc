#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    int sum = 0 ;

    vector <int> v (6, 0) ;
    for ( int i = 0 ; i < 6 ; i ++ ) {
        cin >> v[i] ;
        sum += v[i] ;
    }

    int t, p ;
    cin >> t >> p ;

    int cnt = 0 ;
    for ( int i = 0 ; i < 6 ; i ++ ) {
        if ( v[i] % t == 0 ) cnt += v[i] / t ;
        else cnt += v[i] / t + 1 ;
    }

    cout << cnt << "\n" ;

    cout << sum / p << " " << sum - (p * (sum/p)) ;
    
    return 0 ;
}