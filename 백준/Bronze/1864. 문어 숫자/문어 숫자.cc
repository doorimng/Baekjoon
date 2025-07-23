#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    map <char, int> mp = {
        {'-', 0},
        {'\\', 1},
        {'(', 2},
        {'@', 3},
        {'?', 4},
        {'>', 5},
        {'&', 6},
        {'%', 7},
        {'/', -1} 
    } ;

    while ( true ) {
        string s ;
        cin >> s ;

        if ( s == "#" ) break ;

        int up = 1, ans = 0 ;
        for ( int i = s.size()-1 ; i != -1 ; i -- ) {
            ans += up*mp[s[i]] ;
            up *= 8 ;
        }

        cout << ans << "\n" ;
    }

    return 0 ;
}