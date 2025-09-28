#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[4] = {1, 0, -1, 0} ;
int dy[4] = {0, 1, 0, -1} ;

int n, m, k, ans = INF ;
vector <vector <int>> v ;
vector <vector <int>> origin ;
vector <vector <int>> info ; 

void cycle(int r, int c, int s) {

    if ( s == 0 ) return ;

    int y = r-s, x = c-s ;
    int temp = v[y][x], dir = 0 ;

    while ( dir < 4 ) {
        int yy = y + dy[dir] ;
        int xx = x + dx[dir] ;
        
        y = yy ; x = xx ;
        
        int cur = v[yy][xx] ;
        v[yy][xx] = temp ;
        temp = cur ;

        if ( (yy == r+s && xx == c+s) || (yy == r-s && xx == c-s) || (yy == r+s && xx == c-s) || (yy == r-s && xx == c+s) ) dir ++ ;
    }

    cycle(r, c, s-1) ;
}

void findAns() {
    for ( int i = 1 ; i <= n ; i ++ ) {
        int temp = 0 ;
        for ( int j = 1 ; j <= m ; j ++ ) {
            temp += v[i][j] ;
        }   
        ans = min(ans, temp) ;
    }
}

int visited[10] ;
int temp[10] ;
void btk(int cnt) {
    if ( cnt == k ) {
        v.clear() ;
        v.resize(n+1, vector <int> (m+1, 0)) ;
        copy(origin.begin(), origin.end(), v.begin()) ;

        for ( int i = 0 ; i < k ; i ++ ) {
            cycle(info[temp[i]][0], info[temp[i]][1], info[temp[i]][2]) ;
        }
        findAns() ;
        return ;
    }
    else {
        for ( int i = 0 ; i < k ; i ++ ) {
            if ( !visited[i] ) {
                visited[i] = 1 ;
                temp[cnt] = i ;
                btk(cnt+1) ;
                visited[i] = 0 ;
            }
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> m >> k ;
    v.resize(n+1, vector <int> (m+1, 0)) ;
    origin.resize(n+1, vector <int> (m+1, 0)) ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            int x ;
            cin >> x ;
            
            v[i][j] = origin[i][j] = x ;
        }
    }

    copy(v.begin(), v.end(), origin.begin()) ;

    for ( int i = 0 ; i < k ; i ++ ) {
        int r, c, s ;
        cin >> r >> c >> s ;

        info.push_back({r, c, s}) ;
    }

    btk(0) ;

    cout << ans ;

    return 0 ;
}