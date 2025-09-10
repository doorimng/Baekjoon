#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, c ;
    cin >> n >> c ;

    map <int, pii> mp ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        if ( !mp[x].first ) mp[x].second = i ;
        mp[x].first ++ ;
    }

    vector <vector <int>> v ;

    for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
        v.push_back({it->second.first, -it->second.second, it->first}) ;
    }

    sort(v.begin(), v.end(), greater<>()) ;

    for ( int i = 0 ; i < v.size() ; i ++ ) {
        for ( int j = 0 ; j < v[i][0] ; j ++ ) cout << v[i][2] << " " ;
    }

    return 0 ;
}