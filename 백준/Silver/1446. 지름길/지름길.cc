#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct info {
    int start ;
    int ended ;
    int length ;
} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, d ;
    cin >> n >> d ;

    vector <vector <int>> v ;
    vector <int> road (10005, 0) ;
    for ( int i = 0 ; i <= d ; i ++ ) road[i] = i ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b, c ;
        cin >> a >> b >> c ;

        v.push_back({a, b, c}) ;
    }

    sort(v.begin(), v.end()) ;

    for ( int i = 0 ; i <= d ; i ++ ) {
        for ( int j = 0 ; j < v.size() ; j ++ ) {
            int start = v[j][0] ;
            int ended = v[j][1] ;
            int length = v[j][2] ;

            if ( start == i ) road[ended] = min(road[ended], road[start] + length) ;
            else {
                if ( i == 0 ) road[i] = 0 ;
                else road[i] = min(road[i], road[i-1] + 1) ;
            }
        }
    }

    cout << road[d] ;

    return 0 ;
}