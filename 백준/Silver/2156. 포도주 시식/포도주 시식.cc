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

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        v.push_back(x) ;
    }

    vector <vector <int>> dp (n+1, vector <int> (3, 0)) ;

    dp[0][1] = v[0] ; 
    
    if ( n > 1 ) {
        dp[1][2] = v[0] + v[1] ;
        dp[1][1] = v[1] ;
    
        for ( int i = 2 ; i < n ; i ++ ) {
            dp[i][1] = max(v[i] + max(dp[i-2][1], dp[i-2][2]), max(dp[i-1][1], dp[i-1][2])) ;
            dp[i][2] = max(v[i] + dp[i-1][1], max(dp[i-1][1], dp[i-1][2])) ;
        }
    }

    cout << max(dp[n-1][1], dp[n-1][2]) ;

    return 0 ;
}