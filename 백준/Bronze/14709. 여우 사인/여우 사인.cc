#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    // 2랑 5는 아무것도 안 닿고 1 3 4는 닿아야됨

    int hand[6] = {0, } ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        hand[a] ++ ;
        hand[b] ++ ;
    }

    if ( !hand[2] && !hand[5] ) {
        if ( hand[1] == 2 && hand[3] == 2 && hand[4] == 2 ) {
            cout << "Wa-pa-pa-pa-pa-pa-pow!" ;
            return 0 ;
        }
    }

    cout << "Woof-meow-tweet-squeek" ;

    return 0 ;
}