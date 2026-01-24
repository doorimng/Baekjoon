#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    char c ;
    cin >> c ;

    if ( c == 'M' ) cout << "MatKor" ;
    if ( c == 'W' ) cout << "WiCys" ;
    if ( c == 'C' ) cout << "CyKor" ;
    if ( c == 'A' ) cout << "AlKor" ;
    if ( c == '$' ) cout << "$clear" ;

    return 0 ;
}