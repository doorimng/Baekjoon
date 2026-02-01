#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    double x, y, ans ;
    cin >> x >> y ;
    ans = x/y ;

    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        double a, b ;
        cin >> a >> b ;

        ans = min(ans, a/b) ;
    }

    printf("%.3f", ans*1000) ;

    return 0 ;
}