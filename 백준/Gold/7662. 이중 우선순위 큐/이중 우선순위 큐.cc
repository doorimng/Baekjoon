#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    
    int t ;
    cin >> t ;
    
    while ( t -- ) {
        int k ;
        cin >> k ;

        multiset <int> ms ;

        for ( int i = 0 ; i < k ; i ++ ) {
            char c ;
            int n ;

            cin >> c >> n ;

            if ( c == 'I' ) ms.insert(n) ;
            else {
                if ( ms.empty() ) continue ;

                if ( n == 1 ) ms.erase(--ms.end()) ;
                else ms.erase(ms.begin()) ;
            }
        }

        if ( ms.empty() ) cout << "EMPTY\n" ;
        else {
            auto f = ms.begin() ;
            auto e = --ms.end() ;

            cout << *e << " " << *f << "\n" ;
        }
    }
    
    return 0 ;
}