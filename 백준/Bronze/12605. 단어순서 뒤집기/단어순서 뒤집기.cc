#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    cin.ignore() ;

    for ( int t = 1 ; t <= n ; t ++ ) {
        string s ;
        getline(cin, s) ;

        vector <int> blank ;

        blank.push_back(0) ;

        for ( int i = 0 ; i < s.size() ; i ++ ) {
            if ( s[i] == ' ' ) blank.push_back(i) ;
        }

        blank.push_back(s.size()) ;

        cout << "Case #" << t << ": " ;

        for ( int i = blank.size()-2 ; i != -1 ; i -- ) {
            if ( blank[i] == 0 ) cout << s[0] ;
            for ( int j = blank[i] + 1 ; j < blank[i+1] ; j ++ ) {
                cout << s[j] ;
            }
            cout << " " ;
        }

        cout << "\n" ;
    }

    return 0 ;
}