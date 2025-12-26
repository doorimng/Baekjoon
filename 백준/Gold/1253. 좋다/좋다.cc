#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX


int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;
    vector <ll> v (n, 0);

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;
    }

    sort(v.begin(), v.end()) ;

    int cnt = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int l = 0, r = n-1 ;

        while ( l < r ) {
            // 같은 수 제거
            if ( l == i ) {
                l ++ ; 
                continue ;
            }
            if ( r == i ) {
                r -- ;
                continue ;
            }

            if ( v[l] + v[r] == v[i] ) {
                cnt ++ ;
                // cout << v[l] << " + " << v[r] << " = " << v[i] << "\n" ;
                break ;
            }
            
            if ( v[l] + v[r] >= v[i] ) r -- ;
            else l ++ ;
        }
    }

    cout << cnt ;
    

    return 0 ;
}