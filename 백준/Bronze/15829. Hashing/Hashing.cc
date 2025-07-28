#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

ll Pow(int n) {
    ll ans = 1 ;
    while ( n > 0 ) {
        ans = (ans * 31) % 1234567891 ;
        n -- ;
    }
    return ans % 1234567891 ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n, ans = 0 ;
    string s ;
    cin >> n >> s ;

    for ( int i = 0 ; i < n ; i ++ ) {
        ans += ((s[i] - 'a' + 1) * Pow(i)) % 1234567891 ;
    }

    cout << ans % 1234567891 ;
    
    return 0 ;
}