#include <bits/stdc++.h>

using namespace std ;
typedef unsigned long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> country (n+1, 0) ;
    vector <vector <int>> v ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b, c ;
        cin >> a >> b >> c ;

        v.push_back({c, a, b}) ;
    }

    sort(v.begin(), v.end(), greater<>()) ;

    int cnt = 0 ;
    for ( int i = 0 ; i < v.size() ; i ++ ) {
        int cnum = v[i][1], snum = v[i][2], score = v[i][0] ;

        if ( cnt == 3 ) break ;
        if ( country[cnum] >= 2 ) continue ;

        cout << cnum << " " << snum << "\n" ;
        country[cnum] ++ ; cnt ++ ;
    }

    return 0 ;
}