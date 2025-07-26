#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int k, l ;
    cin >> k >> l ;

    map <string, int> mp ;
    deque <string> q ;

    for ( int i = 0 ; i < l ; i ++ ) {
        string s ;
        cin >> s ;

        mp[s] ++ ;
        q.push_back(s) ;
    }

    while ( k > 0 ) {
        if ( q.empty() ) break ;
        string temp = q.front() ;

        if ( mp[temp] == 1 ) {
            cout << temp << "\n" ;
            k -- ;
        }

        mp[temp] -- ;
        q.pop_front() ;
    }
    
    return 0 ;
}