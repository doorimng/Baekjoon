#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct info {
    int y ;
    int x ;
} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    vector <int> v (3, 0) ;
    
    info A, B, C ;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y ;
    
    v[0] = (B.x-C.x)*(B.x-C.x) + (B.y-C.y)*(B.y-C.y) ; 
    v[1] = (A.x-C.x)*(A.x-C.x) + (A.y-C.y)*(A.y-C.y) ; 
    v[2] = (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y) ; 
    
    sort(v.begin(), v.end()) ;

    int a2 = v[0], b2 = v[1], c2 = v[2] ;

    if ( (A.y-B.y)*(B.x-C.x) == (B.y-C.y)*(A.x-B.x) )  cout << 'X' ;
    else if ( a2 == b2 && b2 == c2 ) cout << "JungTriangle" ;
    else if ( a2 == b2 ) {
        if ( a2+b2 == c2 ) cout << "Jikkak2Triangle" ;
        else cout << "Dunkak2Triangle" ;
    }
    else if ( b2 == c2 ) cout << "Yeahkak2Triangle" ;
    else {
        if ( c2 > a2 + b2 ) cout << "DunkakTriangle" ;
        else if ( c2 < a2 + b2 ) cout << "YeahkakTriangle" ;
        else cout << "JikkakTriangle" ;
    }

    return 0 ;
}