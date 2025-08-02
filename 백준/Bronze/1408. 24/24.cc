#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s, e ;
    cin >> s >> e ;

    int h1, h2, m1, m2, s1, s2 ;
    h1 = stoi(s.substr(0, 2)) ;
    h2 = stoi(e.substr(0, 2)) ;

    m1 = stoi(s.substr(3, 5)) ;
    m2 = stoi(e.substr(3, 5)) ;

    s1 = stoi(s.substr(6)) ;
    s2 = stoi(e.substr(6)) ;

    int h, m, sec ;

    if ( s1 > s2 ) {
        m2 -- ;
        sec = s2+60-s1 ;
    }
    else sec = s2-s1 ;

    if ( m1 > m2 ) {
        h2 -- ;
        m = m2+60-m1 ;
    }
    else m = m2-m1 ;

    h = h2-h1 ;

    if ( h < 0  ) h = 24 + h ;
    else if ( h < 10 ) cout << "0" ;
    cout << h << ":" ;

    if ( m < 10 ) cout << "0" ;
    cout << m << ":" ;

    if ( sec < 10 ) cout << "0" ;
    cout << sec ;

    return 0 ;
}