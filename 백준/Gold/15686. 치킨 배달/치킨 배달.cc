#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m ;

vector <pii> chicken ;
vector <pii> house ;

vector <pii> v ;

int ans = INF ;

void nCr(int start) {
    if ( v.size() == m ) {
        int temp = INF, sum = 0 ;
        for ( int i = 0 ; i < house.size() ; i ++ ) {
            temp = INF ;
            for ( int j = 0 ; j < v.size() ; j ++ ) {
                temp = min(abs(house[i].first-v[j].first)+abs(house[i].second-v[j].second), temp) ;
            }
            sum += temp ;
        }

        ans = min(ans, sum) ;
        return ;
    }

    for ( int i = start + 1 ; i < chicken.size() ; i ++ ) {
        v.push_back(chicken[i]) ;
        nCr(i) ;
        v.pop_back() ;
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m ;
    
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            int x ;
            cin >> x ;

            if ( x == 2 ) chicken.push_back({i, j}) ;
            if ( x == 1 ) house.push_back({i, j}) ;
        }
    }

    nCr(-1) ;

    cout << ans ;
    
    return 0 ;
}