#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

typedef pair <ll, char> plc ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int Q ;
    
    cin >> Q ;
    vector <plc> v (Q+5) ;
    
    for ( int i = 1 ; i <= Q ; i ++ ) {
        ll x ; char c ;
        cin >> x >> c ;
        
        v[i] = {x, c} ;
    }
    
    ll i = (ll) -(1e+18), j = (ll)(1e+18), ans = LLONG_MAX ;
    i -- ; j ++ ; 
    ll cnt = 1 ;
    while ( true ) {

        if ( cnt > Q ) {
            if ( ans != LLONG_MAX ) cout << "I got it!\n" << ans ;
            else cout << "Hmm..." ;
            break ;
        }

        plc temp = v[cnt] ;
        if ( temp.second == '^' ) i = max(i, temp.first) ;
        if ( temp.second == 'v' ) j = min(j, temp.first) ;

        if ( j - i <= 1 ) {
            cout << "Paradox!\n" << cnt ;
            break ;
        }
        else if ( j - i == 2 ) ans = min(ans, cnt) ;

        cnt ++ ;
    }

    return 0 ;
}