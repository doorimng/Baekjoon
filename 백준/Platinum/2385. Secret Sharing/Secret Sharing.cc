#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <string> v, zerov ;
string zero = "" ;

struct cmp{
    bool operator()(string a, string b) {
        return a+zero+b < b+zero+a ;
    }
} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        if ( s[0] == '0' ) zerov.push_back(s) ;
        else v.push_back(s) ;
    }

    if ( v.empty() ) {
        cout << "INVALID" ;
        return 0 ;
    }

    sort(zerov.begin(), zerov.end(), cmp()) ;
    for ( int i = 0 ; i < zerov.size() ; i ++ ) zero += zerov[i] ;
    
    sort(v.begin(), v.end(), cmp()) ;
    cout << v[0] << zero ;
    v.erase(v.begin(), v.begin()+1) ;
    zero = "" ;
    sort(v.begin(), v.end(), cmp()) ;

    for ( int i = 0 ; i < v.size() ; i ++ ) cout << v[i] ;

    return 0 ;
}