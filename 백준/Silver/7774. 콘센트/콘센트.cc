#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    vector <int> a(n, 0), b(m, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) cin >> a[i] ;
    for ( int i = 0 ; i < m ; i ++ ) cin >> b[i] ;

    sort(a.begin(), a.end()) ;
    sort(b.begin(), b.end()) ;

    int concent_A = 0, concent_B = a.back() ;
    a.pop_back() ;

    int Mx = 0 ;
    while ( true ) {

        if ( b.empty() ) break ;

        Mx = max(Mx, concent_A) ;

        while ( concent_B && !b.empty() ) {
            concent_B -- ;
            concent_A += b.back() ;
            b.pop_back() ;
        }
    
        Mx = max(Mx, concent_A) ;

        if ( a.empty() ) break ;

        concent_A -- ;
        concent_B += a.back() ;
        a.pop_back() ;
        
    }

    cout << Mx ;

    return 0 ;
}