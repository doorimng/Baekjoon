#include <iostream>
#include <map>

using namespace std ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, p ;
    cin >> n >> p ;

    int w, l, g ;
    cin >> w >> l >> g ;

    map <string, int> mp ;
    for ( int i = 0 ; i < p ; i ++ ) {
        string s ;
        char c ;
        cin >> s >> c ;

        if ( c == 'W' ) mp[s] = w ;
        else mp[s] = -l ;
    }

    int score = 0, canWin = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        if ( mp[s] != w ) mp[s] = -l ;
        score = max(0, score+mp[s]) ;
        if ( score >= g ) canWin = 1 ;
    }

    if ( !canWin )  cout << "I AM IRONMAN!!" ;
    else cout << "I AM NOT IRONMAN!!" ;


    return 0 ;
}