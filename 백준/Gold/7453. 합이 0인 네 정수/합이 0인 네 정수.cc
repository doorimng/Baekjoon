#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n ;
    cin >> n ;

    vector <ll> a(n, 0), b(n, 0), c(n, 0), d(n, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] ;
    }

    vector <ll> ab, cd ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            ab.push_back(a[i] + b[j]) ;
            cd.push_back(c[i] + d[j]) ;
        }
    }

    sort(ab.begin(), ab.end()) ;
    sort(cd.begin(), cd.end()) ;

    ll low = 0, high = cd.size()-1, ans = 0 ;

    while ( low < ab.size() && high >= 0 ) {

        if ( ab[low] + cd[high] == 0 ) {
            ll cntAB = 1, cntCD = 1 ;
            while ( true ) {
                low ++ ;
                if ( low >= ab.size() ) break ; // 범위 벗어남
                if ( ab[low] == ab[low-1] ) cntAB ++ ; // 똑같은 거 있으면 세기
                else break ; 
            }
            while ( true ) {
                high -- ;
                if ( high < 0 ) break ; // 범위 벗어남
                if ( cd[high] == cd[high+1] ) cntCD ++ ; // 똑같은 거 있으면 세기
                else break ;
            }
            ans += cntAB * cntCD ;
        }
        else {
            if ( ab[low] + cd[high] > 0 ) {
                high -- ;
            }
            else {
                low ++ ;
            }
        }
    }

    cout << ans ;

    return 0 ;
}