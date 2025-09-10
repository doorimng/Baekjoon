#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct cmp {
    bool operator()(const string &a, const string &b) const {
        if ( a[0] == '-' && b[0] == '-' ) {
            if ( a.size() != b.size() ) return a.size() > b.size() ;
            else return a > b ;
        }
        else if ( a[0] == '-' || b[0] == '-' ) {
            return a[0] < b[0] ;
        }
        else {
            if ( a.size() != b.size() ) return a.size() < b.size() ;
            else return a < b ;
        }
    }
} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    int Mx = 0 ;
    map <string, int, cmp> mp ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string x ;
        cin >> x ;

        mp[x] ++ ;
        Mx = max(Mx, mp[x]) ;
    }

    for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
        if ( it->second == Mx ) {
            cout << it->first ;
            return 0 ;
        }
    }

    return 0 ;
}