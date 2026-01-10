#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    double s, ss, n, nn, u, uu ;
    cin >> s >> ss >> n >> nn >> u >> uu ;

    double a = ss*10 / ((s*10 >= 5000) ? s*10-500 : s*10) ;
    double b = nn*10 / ((n*10 >= 5000) ? n*10-500 : n*10) ;
    double c = uu*10 / ((u*10 >= 5000) ? u*10-500 : u*10) ;

    if ( max(a, max(b, c)) == a ) cout << 'S' ;
    else if ( max(a, max(b, c)) == b ) cout << 'N' ;
    else cout << 'U' ;

    return 0 ;
}