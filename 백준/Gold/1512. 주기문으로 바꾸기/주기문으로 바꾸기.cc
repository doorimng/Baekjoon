#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int m, ans = INF ;
    string s ;

    cin >> m >> s ;

    vector <int> visited (s.size(), 0) ;

    for ( int M = 1 ; M <= m ; M ++ ) {
        int temp = 0 ;
        for ( int i = 0 ; i < M ; i ++ ) {
            vector <int> v (4, 0) ;
            for ( int j = i ; j < s.size() ; j += M ) {
                if ( s[j] == 'A' ) v[0] ++ ;
                if ( s[j] == 'C' ) v[1] ++ ;
                if ( s[j] == 'G' ) v[2] ++ ;
                if ( s[j] == 'T' ) v[3] ++ ;
            }
    
            int sum = 0, Mx = 0 ;
            for ( int i = 0 ; i < 4 ; i ++ ) {
                sum += v[i] ;
                Mx = max(Mx, v[i]) ;
            }
            temp += sum - Mx ;
        }   
        ans = min(temp, ans) ;
    }

    cout << ans ;
    
    return 0 ;
}