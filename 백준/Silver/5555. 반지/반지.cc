#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s ;
    cin >> s ;

    int n, cnt = 0 ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string t ;
        cin >> t ;

        t += t ;

        int check = 0 ;
        for ( int j = 0 ; j < t.size() / 2 ; j ++ ) {
            if ( t.substr(j, s.size()) == s ) check = 1 ;
        }

        cnt += check ;
    }

    cout << cnt ;

    return 0 ;
}