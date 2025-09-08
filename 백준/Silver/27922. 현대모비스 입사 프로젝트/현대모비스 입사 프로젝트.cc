#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct cmp_a {
    bool operator()(vector <int> a, vector <int> b) {
        return a[0] > b[0] ;
    }
} ;

struct cmp_b {
    bool operator()(vector <int> a, vector <int> b) {
        return a[1] > b[1] ;
    }
} ;

struct cmp_c {
    bool operator()(vector <int> a, vector <int> b) {
        return a[2] > b[2] ;
    }
} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    ll n, k ;
    cin >> n >> k ;

    vector <vector <int>> v ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b, c ;
        cin >> a >> b >> c ;

        v.push_back({a+b, b+c, c+a}) ;
    }

    sort(v.begin(), v.end(), cmp_a()) ;
    ll ans = 0, Mx = 0 ;
    for ( int i = 0 ; i < k ; i ++ ) {
        ans += v[i][0] ;
    }
    Mx = max(Mx, ans) ;

    sort(v.begin(), v.end(), cmp_b()) ;
    ans = 0 ;
    for ( int i = 0 ; i < k ; i ++ ) {
        ans += v[i][1] ;
    }

    Mx = max(Mx, ans) ;

    sort(v.begin(), v.end(), cmp_c()) ;
    ans = 0 ;
    for ( int i = 0 ; i < k ; i ++ ) {
        ans += v[i][2] ;
    }

    cout << max(Mx, ans) ;

    return 0 ;
}