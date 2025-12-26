#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX


int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, d, k, c ;
    cin >> n >> d >> k >> c ;

    vector <int> v (n+n, 0) ;
    vector <int> check (d+1, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        v[i] = x ;
        v[i+n] = x ;
    }

    int Mx, cnt = 0 ;
    for ( int i = 0 ; i < k ; i ++ ) {
        if ( check[v[i]] == 0 ) cnt ++ ; 
        check[v[i]] ++ ;
    }

    if ( check[c] == 0 ) cnt ++ ;
    Mx = cnt ;
    if ( check[c] == 0 ) cnt -- ;
    // cout << cnt << "\n" ;

    for ( int i = k ; i < n+k-1 ; i ++ ) {
        
        check[v[i-k]] -- ;
        if ( check[v[i-k]] == 0 ) cnt -- ;
        check[v[i]] ++ ;
        if ( check[v[i]] == 1 ) cnt ++ ; 

        if ( check[c] == 0 ) cnt ++ ;

        // cout << i-k+1 << " " << i << "\n" ;
        // cout << v[i-k+1] << " " << v[i] << " " << cnt << "\n---\n" ;

        Mx = max(Mx, cnt) ;

        if ( check[c] == 0 ) cnt -- ;
    }

    cout << Mx ;

    return 0 ;
}