#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v ; 
    map <int, vector <int>> mp ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        v.push_back(x) ;
    }

    vector <int> score (1000005, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 1 ; j <= sqrt(v[i]) ; j ++ ) {
            if ( v[i] % j == 0 ) {
                mp[v[i]].push_back(j) ;
                if ( j*j != v[i] ) mp[v[i]].push_back(v[i]/j) ;
            }
        }
        mp[v[i]].push_back(v[i]) ;
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int x : mp[v[i]] ) {
            if ( !mp[x].empty() ) {
                score[x] ++ ;
                score[v[i]] -- ;
            }
        }
    }

    for ( int i = 0 ; i < n ; i ++ ) cout << score[v[i]] << " " ;

    return 0 ;
}