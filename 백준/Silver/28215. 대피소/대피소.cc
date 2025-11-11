#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, k, ans = INF ;

vector <pii> v ;

int temp[3] = {0, } ;
vector <int> visited (50, 0) ;
void btk(int start, int cnt) {
    if ( cnt == k ) {
        int Mx = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) {
            int Mn = INF ;
            for ( int j = 0 ; j < k ; j ++ ) {
                int dir = abs(v[i].first - v[temp[j]].first) + abs(v[i].second - v[temp[j]].second) ;
                Mn = min(Mn, dir) ;
            }
            Mx = max(Mx, Mn) ;
        }
        ans = min(ans, Mx) ;
        return ;
    }

    for ( int i = start ; i < n ; i ++ ) {
        if ( !visited[i] ) {
            visited[i] = 1 ;
            temp[cnt] = i ;
            btk(i+1, cnt+1) ;
            visited[i] = 0 ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> k ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int y, x ;
        cin >> y >> x ;
    
        v.push_back({y, x}) ;
    }

    btk(0, 0) ;
        
    cout << ans ;

    return 0 ;
}
