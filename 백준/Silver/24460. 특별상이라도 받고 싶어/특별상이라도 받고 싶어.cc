// 분할정복

#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <int>> v ;
vector <int> ansArray = {0, 0, 0, 0} ;

int f(int y, int x, int k) {
    int ans[4] = {0, 0, 0, 0} ;
    if ( k >= 2 ) {
        ans[0] = f(y, x, k/2) ;
        ans[1] = f(y, x+k/2, k/2) ;
        ans[2] = f(y+k/2, x, k/2) ;
        ans[3] = f(y+k/2, x+k/2, k/2) ;
        sort(ans, ans+4) ;
        return ans[1] ;
    }
    else return  v[y][x] ;
}


int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    v.resize(n+1, vector <int> (n+1, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    cout << f(0, 0, n) ;

    return 0 ;
}