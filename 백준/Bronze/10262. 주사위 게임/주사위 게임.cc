#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int a, b, c, d ;
    int aa, bb, cc, dd ;

    cin >> a >> b >> c >> d ;
    cin >> aa >> bb >> cc >> dd ;

    vector <int> va ;
    for ( int i = a ; i <= b ; i ++ ) {
        for ( int j = c ; j <= d ; j ++ ) {
            va.push_back(i+j) ;
        }
    }

    vector <int> vb ;
    for ( int i = aa ; i <= bb ; i ++ ) {
        for ( int j = cc ; j <= dd ; j ++ ) {
            vb.push_back(i+j) ;
        }
    }

    int g = 0, e = 0 ;
    for ( int i = 0 ; i < va.size() ; i ++ ) {
        for ( int j = 0 ; j < vb.size() ; j ++ ) {
            if ( va[i] > vb[j] ) g ++ ;
            else if ( va[i] < vb[j] ) e ++ ;
        }
    }

    if ( g > e ) cout << "Gunnar" ;
    else if ( g == e ) cout << "Tie" ;
    else cout << "Emma" ;

    return 0 ;
}