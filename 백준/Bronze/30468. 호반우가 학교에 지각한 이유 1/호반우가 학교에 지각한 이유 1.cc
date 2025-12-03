#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int a, b, c, d, n ;
    cin >> a >> b >> c >> d >> n ;

    n *= 4 ;

    cout << max(0, n - (a+b+c+d)) ;

    return 0 ;
}