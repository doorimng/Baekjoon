#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s ;
    cin >> s ;

    if ( s == "NLCS" ) cout << "North London Collegiate School" ;
    if ( s == "BHA" ) cout << "Branksome Hall Asia" ;
    if ( s == "KIS" ) cout << "Korea International School" ;
    if ( s == "SJA" ) cout << "St. Johnsbury Academy" ;

    return 0 ;
}