#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct cmp{
    bool operator()(string a, string b) {
        return a+b > b+a ;
    }
} ;

struct cmp_int{
    bool operator()(string a, string b) {
        return stoi(a) < stoi(b) ;
    }
} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int k, n ;
    cin >> k >> n ;

    vector <string> v ;

    for ( int i = 0 ; i < k ; i ++ ) {
        string s ;
        cin >> s ;

        v.push_back(s) ;
    }

    sort(v.begin(), v.end(), cmp_int()) ;

    for ( int i = 0 ; i < n-k ; i ++ ) v.push_back(v[v.size()-1]) ;

    sort(v.begin(), v.end(), cmp()) ;

    for ( int i = 0 ; i < v.size() ; i ++ ) cout << v[i] ;

    return 0 ;
}