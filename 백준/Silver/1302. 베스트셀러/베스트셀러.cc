#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    map <string, int> mp ;
    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        mp[s] ++ ;
    }

    vector <pair <int, string>> v ;
    for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
        v.push_back({-it->second, it->first}) ;
    }

    sort(v.begin(), v.end()) ;

    cout << v[0].second ;

    return 0 ;
}