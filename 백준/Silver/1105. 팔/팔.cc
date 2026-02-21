#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int a, b, cnt = 0 ;
    cin >> a >> b ;

    string aa = to_string(a), bb = to_string(b) ;

    if ( aa == bb ) {
        for ( int i = 0 ; i < aa.size() ; i ++ ) {
            if ( aa[i] == '8' ) cnt ++ ;
        }
    }
    else if ( aa.size() == bb.size() ) {
        for ( int i = 0 ; i < aa.size() ; i ++ ) {
            if ( aa[i] == bb[i] ) {
                if ( aa[i] == '8' ) cnt ++ ;
            }
            else break ;
        }
    }
    
    cout << cnt ;

    return 0 ;
}