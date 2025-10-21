#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
    
    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        int a, b, c ;
        cin >> s >> a >> b >> c ;

        cout << s << " " << a+b+c << " " ;

        if ( a + b + c >= 55 ) {
            if ( a > 10 && b > 7 && c >= 12 ) cout << "PASS\n" ;
            else cout << "FAIL\n" ;
        }
        else cout << "FAIL\n" ;
    }

    return 0 ;
}