#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    vector <ll> v ;

    v.push_back(1) ;
    v.push_back(1) ;

    while ( true ) {
        ll temp = v[v.size()-2] + v[v.size()-1] ;

        if ( temp > 10000000000000000 ) break ;
    
        v.push_back(temp) ;
    }

    map <ll, int> mp1 ;
    map <ll, int> mp2 ;
    map <ll, int> mp3 ;

    for ( int i = 0 ; i < v.size() ; i ++ ) {
        mp1[v[i]] = 1 ;
        for ( int j = 0 ; j < v.size() ; j ++ ) {
            mp2[v[i] + v[j]] = 1 ; 
            for ( int k = 0 ; k < v.size() ; k ++ ) {
                mp3[v[i] + v[j] + v[k]] = 1 ;
            }
        }
    }

    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        ll k, x ;
        cin >> k >> x ;

        if ( k == 1 ) {
            if ( mp1[x] ) cout << "YES\n" ;
            else cout << "NO\n" ;
        }
        else if ( k == 2 ) {
            if ( mp2[x] ) cout << "YES\n" ;
            else cout << "NO\n" ;
        }
        else {
            if ( mp3[x] ) cout << "YES\n" ;
            else cout << "NO\n" ;
        }
    }

    return 0 ;
}