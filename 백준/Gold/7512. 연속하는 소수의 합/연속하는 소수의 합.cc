#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

#define N 10000000
vector <int> v (N+1, 0) ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    v[0] = v[1] = 1 ;   
    for ( int i = 2 ; i <= sqrt(N) ; i ++ ) {
        if ( !v[i] ) {
            for ( int j = i+i ; j <= N ; j += i ) {
                v[j] = 1 ;
            }
        }
    }
    
    vector <ll> sosu ;
    sosu.push_back(0) ;
    for ( int i = 2 ; i <= N ; i ++ ) {
        if ( !v[i] ) sosu.push_back(sosu[sosu.size()-1]+i) ;
    }

    // cout << sosu.size() << " " << sosu[sosu.size()-1] ;
    // ll size = sosu[10000] - sosu[0] ;
    // cout << size ;

    int cnt = 1, t ;
    cin >> t ;

    while ( cnt <= t ) {
        ll n, Mx = 0, ans = 0 ;
        cin >> n ;

        // ll size = sosu[10001] - sosu[0] ;

        vector <int> temp ;
        // vector <ll> sum (size+1, 0) ;
        map <ll, int> mp ;
        for ( int i = 0 ; i < n ; i ++ ) {
            ll x ;
            cin >> x ;
            temp.push_back(x) ;

            Mx = max(Mx, x) ;
        }

        for ( int i = Mx ; i < sosu.size() ; i ++ ) {
            for ( int j = 0 ; j < temp.size() ; j ++ ) {
                mp[sosu[i] - sosu[i-temp[j]]] ++ ;

                if ( mp[sosu[i] - sosu[i-temp[j]]] == n 
                    && !v[sosu[i] - sosu[i-temp[j]]] ) {
                    ans = sosu[i] - sosu[i-temp[j]] ;
                    i = sosu.size() ;
                    break ;
                }
            }
        }

        cout << "Scenario " << cnt ++ << ":\n" << ans << "\n\n" ;
    }

    return 0 ;
}