#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll a, b ;
    cin >> a >> b ;

    ll A = min(a, b) ;
    ll B = max(a, b) ;

    if ( (B-A) % 2 ) cout << (A+B) * ((B-A+1)/2) ;
    else cout << (A+B+1) * (((B+1)-A+1)/2) - (B+1) ;
 
    return 0 ;
}