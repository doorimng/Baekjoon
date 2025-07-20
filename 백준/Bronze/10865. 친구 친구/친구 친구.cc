#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    vector <vector <int>> friends (n+1) ;

    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        friends[a].push_back(b) ;
        friends[b].push_back(a) ;
    }

    for ( int i = 1 ; i <= n ; i ++ ) cout << friends[i].size() << "\n" ;

    return 0 ;
}