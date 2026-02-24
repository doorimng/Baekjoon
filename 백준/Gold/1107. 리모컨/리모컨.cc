// 1339
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

// string s, temp = "" ;
int n, m, nums[10] = {0, } ;
// pii channels = {0, 0} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m, channel = 100 ;
    cin >> n >> m ;

    for ( int i = 0 ; i < m ; i ++ ) {
        int x ;
        cin >> x ;

        nums[x] = 1 ;
    }

    for ( int i = 0 ; i < 1000000 ; i ++ ) {
        string s = to_string(i) ;
        int check = 0 ;

        for ( int j = 0 ; j < s.size() ; j ++ ) {
            if ( nums[s[j]-'0'] ) {
                check = 1 ;
                break ;
            }
        }

        if ( check ) continue ;
        else {
            if ( abs(i-n) < abs(channel-n) ) channel = i ;
        }
    }


    int ans = abs(channel-n) ;
    if ( ans + to_string(channel).size() <= abs(100-n) ) 
        ans += to_string(channel).size() ;
    else ans = abs(100-n) ;

    cout << ans ;

    return 0 ;
}