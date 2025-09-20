#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, Mn = 300, Mx = -1;
int dx[4] = {1, -1, 0, 0} ;
int dy[4] = {0, 0, 1, -1} ;

vector <vector <int>> v ;
vector <vector <int>> visited ;

queue <pii> q ;
bool BFS(int mid) {
    for ( int k = Mn ; k <= Mx ; k ++ ) {
        visited.clear() ;
        visited.resize(n, vector <int> (n, 0)) ;

        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < n ; j ++ ) {
                if ( k <= v[i][j] && v[i][j] <= k+mid ) visited[i][j] = 0 ;
                else visited[i][j] = 1 ;
            }
        }

        if ( !visited[0][0] ) q.push({0, 0}) ;

        while ( !q.empty() ) {
            int y = q.front().first ;
            int x = q.front().second ;
            q.pop() ;

            if ( y == n-1 && x == n-1 ) return 1 ;
    
            for ( int i = 0 ; i < 4 ; i ++ ) {
                int yy = y + dy[i] ;
                int xx = x + dx[i] ;
    
                if ( yy < 0 || yy >= n || xx < 0 || xx >= n ) continue ;
                if ( visited[yy][xx] ) continue ;  
    
                visited[yy][xx] = 1 ;
                q.push({yy, xx}) ;
            }
        }
    }
    return 0 ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;

    v.resize(n, vector <int> (n, 0)) ;
    visited.resize(n, vector <int> (n, 0)) ;
    
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            cin >> v[i][j] ;
            Mn = min(Mn, v[i][j]) ;
            Mx = max(Mx, v[i][j]) ;
        }
    }
    
    int low = 0, high = 200 ;
    int ans = INF ;
    while ( low <= high ) {
        int mid = (low + high) / 2 ;
        
        while ( !q.empty() ) q.pop() ;
    
        int k = BFS(mid) ;

        if ( k ) {
            ans = min(ans, mid) ;
            high = mid - 1 ;
        }
        else low = mid + 1 ;
    }

    cout << ans ;

    return 0 ;
}