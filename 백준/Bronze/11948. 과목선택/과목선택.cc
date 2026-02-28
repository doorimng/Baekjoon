#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int sum = 0, Mn = INF ;
    for ( int i = 0 ; i < 4 ; i ++ ) {
        int x ;
        cin >> x ;

        sum += x ;
        Mn = min(Mn, x) ;
    }
    sum -= Mn ;

    int a, b ;
    cin >> a >> b ;
    sum += max(a, b) ;

    cout << sum ;

    return 0 ;
}