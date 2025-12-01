#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    string s ;
    cin >> s ;

    int q ;
    cin >> q ;

    while ( q -- ) {
        int l, r, Mx = 0 ;
        cin >> l >> r ;

        string temp = s.substr(l-1, (r-l) +1) ;
        
        for ( int i = 1 ; i <= r-l ; i ++ ) {
            string f = temp.substr(0, i) ;
            string se = temp.substr(i) ;

            reverse(f.begin(), f.end()) ;

            int score = 0 ;
            for ( int j = 0 ; j < min(f.size(), se.size()) ; j ++ ) {
                if ( f[j] == se[j] ) score ++ ;
            }

            Mx = max(Mx, score) ;
        }
        cout << Mx << "\n" ;
    }

    return 0 ;
}