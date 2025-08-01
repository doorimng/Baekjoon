#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, Mx = -1 ;
    cin >> n ;

    vector <int> v ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        v.push_back(x) ;
    }

    sort(v.begin(), v.end()) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        Mx = max(Mx, v[i]*(n-i)) ;
    }

    cout << Mx ;

    return 0 ;
}