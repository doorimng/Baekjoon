#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> soldier (n+1, 0) ;
    vector <int> v (2000005, 0) ;

    for ( int i = 1 ; i <= n ; i ++ ) cin >> soldier[i] ;

    if ( n == 1 ) {
        cout << "권병장님, 중대장님이 찾으십니다" ;
        return 0 ;
    }

    int Mx = -1 ;
    for ( int i = 1 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        if ( i == 1 || soldier[i] <= Mx ) {
            v[soldier[i]] += 1 ;
            v[soldier[i]+x+1] -= 1 ;
            
            Mx = max(Mx, soldier[i] + x) ;
        }
    }

    for ( int i = 1 ; i <= 2000005 ; i ++ ) v[i] += v[i-1] ;

    if ( v[soldier[n]] > 0 ) cout << "권병장님, 중대장님이 찾으십니다" ;
    else cout << "엄마 나 전역 늦어질 것 같아" ;

    return 0 ;
}