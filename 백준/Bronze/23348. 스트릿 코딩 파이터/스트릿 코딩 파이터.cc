#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int A, B, C, n, sum = 0 ;
    cin >> A >> B >> C >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int aa = 0, bb = 0, cc = 0 ;
        for ( int j = 0 ; j < 3 ; j ++ ) {
            int a, b, c ;
            cin >> a >> b >> c ;

            aa += a ;
            bb += b ;
            cc += c ;
        }
        sum = max(sum, aa*A+bb*B+cc*C) ;
    }

    cout << sum ;

    return 0 ;
}