#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v (55, 0) ;
    vector <int> ans (55, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        v[x] ++ ;
    }

    ans[1] = v[1] ;

    for ( int i = 2 ; i <= n ; i ++ ) {
        ans[i] = v[i] * ans[i-1] ;
    }

    int sum = 0 ;

    for ( int i = 1 ; i <= n ; i ++ ) sum += ans[i] ;
    cout << sum ;

    return 0 ;
}