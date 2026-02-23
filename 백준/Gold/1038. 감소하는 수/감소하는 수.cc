#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    map <ll, int> mp ;

    for ( int i = 0 ; i < 10 ; i ++ ) {
        vector <ll> temp ;
        for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
            string s = to_string(it->first) ;
            s = (char)(i+'0')+s ;

            temp.push_back(stoll(s)) ;
        }

        mp[i] = 1 ;
        for ( int j = 0 ; j < temp.size() ; j ++ ) {
            mp[temp[j]] = 1 ;
        }
    }

    int n, cnt = 0 ;
    cin >> n ;

    for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
        if ( cnt++ == n ) {
            cout << it->first ;
            return 0 ;
        } 
    }

    cout << -1 ;

    return 0 ;
}