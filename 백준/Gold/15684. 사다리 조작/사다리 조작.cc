#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m, h, ans = INF ;
vector <vector <int>> v ;

int play() {
    for ( int i = 1 ; i <= n ; i ++ ) {
        int temp = i ;
        
        for ( int j = 1 ; j <= h ; j ++ ) {
            if ( v[j][temp] ) temp ++ ;
            else if ( v[j][temp-1] ) temp -- ;
        }
        if ( temp != i ) return 0 ;
    }

    return 1 ;

}

void ladder(int y, int step) {
    if ( step > 3 || step >= ans ) return ;

    if ( play() ) {
        ans = min(ans, step) ;
        return ;
    }

    for ( int i = y ; i <= h ; i ++ ) {
        for ( int j = 1 ; j < n ; j ++ ) {
            if ( v[i][j] || v[i][j-1] || v[i][j+1] ) continue ;

            v[i][j] = 1 ;
            ladder(i, step+1) ;
            v[i][j] = 0 ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m >> h ;

    v.resize(h+2, vector <int> (n+2, 0)) ;

    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        v[a][b] = 1 ;
    }

    ladder(1, 0) ;

    if ( ans == INF ) ans = -1 ;
    
    cout << ans ;

    return 0 ;
}