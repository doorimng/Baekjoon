#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    ll MnX = INF, MnY = INF, MxX = -INF, MxY = -INF ;
    for ( int i = 0 ; i < n ; i ++ ) {
        ll x, y ;
        cin >> x >> y ;

        MnX = min(MnX, x) ;
        MxX = max(MxX, x) ;
        MnY = min(MnY, y) ;
        MxY = max(MxY, y) ;
    }

    cout << (MxX - MnX) * (MxY - MnY) ;

    return 0 ;
}