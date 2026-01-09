#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int n, m ;
    cin >> n >> m ;

    int a, b, c, d ;
    cin >> a >> b >> c >> d ;

    if ( abs(a-c) == 1 && abs(b-d) == 2 ) cout << "LOHA" ;
    else if ( abs(a-c) == 2 && abs(b-d) == 1 ) cout << "LOHA" ;
    else cout << "HANYANG" ;

    return 0 ;
}