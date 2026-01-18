#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct cmp {
    bool operator()(string a, string b) {
        if ( a.size() == b.size() ) return a < b ;
        else return a.size() < b.size() ;
    }
} ;

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <string> v (n, "") ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> v[i] ;
    }

    sort(v.begin(), v.end(), cmp()) ;

    int cnt = n ;

    for ( int i = 0 ; i < n-1 ; i ++ ) {
        for ( int j = i+1 ; j < n ; j ++ ) {
            if ( v[j].substr(0, v[i].size()) == v[i] ) {
                cnt -- ;
                break ;
            }
        }
    }

    cout << cnt ;

    return 0 ;
}