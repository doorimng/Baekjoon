#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, m, k ;
vector <vector <int>> v ;
vector <vector <int>> visited ;

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

int ans = -INF ;

int temp[100] = {0, } ;

void btk(int cnt, int start) {
    if ( cnt == k ) {
        int sum = 0 ;
        for ( int i = 0 ; i < k ; i ++ ) {
            int y = temp[i] / m, x = temp[i] % m ;
            sum += v[y][x] ;
        }
        ans = max(ans, sum) ;
        return ;
    }

    for ( int i = start ; i < n*m ; i ++ ) {
        int y = i / m, x = i % m ;
        if ( !visited[y][x] ) {
            visited[y][x] ++ ;
            for ( int j = 0 ; j < 4 ; j ++ ) {
                int yy = y + dy[j] ;
                int xx = x + dx[j] ;

                if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;

                visited[yy][xx] ++ ;
            }
            temp[cnt] = i ;
            btk(cnt+1, i+1) ;
            visited[y][x] -- ;
            for ( int j = 0 ; j < 4 ; j ++ ) {
                int yy = y + dy[j] ;
                int xx = x + dx[j] ;

                if ( yy < 0 || yy >= n || xx < 0 || xx >= m ) continue ;

                visited[yy][xx] -- ;
            }
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m >> k ;

    v.resize(n, vector <int> (m, 0)) ;
    visited.resize(n, vector <int> (m, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> v[i][j] ;
        }
    }

    btk(0, 0) ;

    cout << ans ;

    return 0 ;
}