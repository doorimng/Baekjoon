#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        int n, l1, l2, s1, s2 ;
        cin >> n >> l1 >> l2 >> s1 >> s2 ;

        vector <int> pass1 (n+1, 0), pass2 (n+1, 0), dribble1 (n+1, 0), dribble2 (n+1, 0) ;
        vector <int> dp1 (n+1, 0), dp2 (n+1, 0) ;

        for ( int i = 1 ; i < n ; i ++ ) cin >> pass1[i] ;
        for ( int i = 1 ; i < n ; i ++ ) cin >> dribble1[i] ;
        for ( int i = 1 ; i < n ; i ++ ) cin >> pass2[i] ;
        for ( int i = 1 ; i < n ; i ++ ) cin >> dribble2[i] ;

        dp1[1] = l1 ;
        dp2[1] = l2 ;

        pass1[n-1] += s2 ; dribble1[n-1] += s1 ;
        pass2[n-1] += s1 ; dribble2[n-1] += s2 ;

        for ( int i = 2 ; i <= n ; i ++ ) {
            dp1[i] = min(dp2[i-1] + pass2[i-1], dp1[i-1] + dribble1[i-1]) ;
            dp2[i] = min(dp1[i-1] + pass1[i-1], dp2[i-1] + dribble2[i-1]) ;
        }
        
        cout << min(dp1[n], dp2[n]) << "\n" ;
    }

    return 0 ;
}