#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

typedef pair <ll, char> plc ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    // 2^15 = 32,768

    int n ;
    cin >> n ;

    vector <int> v ;
    map <int, int> mp ;

    for ( int i = 1 ; i <= 2*n ; i *= 2 ) {
        v.push_back(i) ;
    }

    int dir = v.size()-1 ;
    for ( int i = n ; i != 0 ; i -- ) {
        if ( mp[i] ) continue ;

        if ( i == v[dir] / 2 ) {
            dir -- ;
            mp[i] = i ;
        } 
        else if ( i < v[dir] / 2 ) {
            dir -- ;
            i ++ ;
        }
        else {
            mp[i] = v[dir] - i ;
            mp[v[dir] - i] = i ;
        }

    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << mp[i] << "\n" ;
        // cout << i << " : " << mp[i] << "\n" ;
    }

    // for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
    //     // cout << it->second << "\n" ;
    //     cout << it->first << " : " << it->second << "\n"; 
    // }

    return 0 ;
}