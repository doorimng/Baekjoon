#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    vector <vector <int>> v ;

    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        char c ;

        cin >> a >> b >> c ;

        v.push_back({b, a, c}) ;
    }

    sort(v.begin(), v.end()) ;

    for ( int i = 0 ; i < v.size() ; i ++ ) cout << (char) v[i][2] ;

    return 0 ;
}