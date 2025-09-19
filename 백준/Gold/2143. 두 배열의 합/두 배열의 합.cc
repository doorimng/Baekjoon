#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t, n, m ;
    cin >> t >> n ;

    vector <ll> a (n, 0) ;

    cin >> a[0] ;
    for ( int i = 1 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        a[i] = x + a[i-1] ;
    }

    cin >> m ;
    vector <ll> b (m, 0) ;

    cin >> b[0] ;
    for ( int i = 1 ; i < m ; i ++ ) {
        int x ;
        cin >> x ;

        b[i] = x + b[i-1] ;
    }

    vector <ll> A, B ;

    for ( int i = 0 ; i < n ; i ++ ) {
        A.push_back(a[i]) ;
        if ( i == n-1 ) break ;
        for ( int j = i+1 ; j < n ; j ++ ) {
            A.push_back(a[j] - a[i]) ;
        }
    }

    for ( int i = 0 ; i < m ; i ++ ) {
        B.push_back(b[i]) ;
        if ( i == m-1 ) break ;
        for ( int j = i+1 ; j < m ; j ++ ) {
            B.push_back(b[j] - b[i]) ;
        }
    }

    sort(A.begin(), A.end()) ;
    sort(B.begin(), B.end()) ;

    ll low = 0, high = B.size() - 1, cnt = 0 ;
    while ( low < A.size() && high >= 0 ) {
        if ( A[low] + B[high] == t ) {
            ll aa = 1, bb = 1 ;

            while ( true ) {
                low ++ ;
                if ( low >= A.size() ) break ;
                if ( A[low] != A[low-1] ) break ;

                aa ++ ;
            }

            while ( true ) {
                high -- ;
                if ( high < 0 ) break ;
                if ( B[high] != B[high+1] ) break ;

                bb ++ ;
            }

            cnt += aa * bb ;
        }
        else if ( A[low] + B[high] > t ) high -- ;
        else low ++ ;
    }
    
    cout << cnt ;

    return 0 ;
}