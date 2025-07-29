#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll a, b, v ;
    cin >> a >> b >> v ;

    cout << (v-b-1) / (a-b) + 1 ;

    return 0 ;
}