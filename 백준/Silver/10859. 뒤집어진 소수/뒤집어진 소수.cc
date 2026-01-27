#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int check(ll n) {
    if ( n == 1 ) return 0 ;
    if ( n == 2 ) return 1 ; 
    if ( n % 2 == 0 ) return 0 ;
    ll temp = (ll)sqrt(n) ;
    for ( ll i = 3 ; i <= temp+1 ; i += 2 ) {
        if ( n % i == 0 ) return 0 ;
    }
    return 1 ;
}

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    string s ;
    cin >> s ;

    int solved = check(stoll(s)) ;
    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( s[i] == '3' || s[i] == '4' || s[i] == '7' ) {
            solved = false ;
            break ;
        }
        if ( s[i] == '6' ) s[i] = '9' ;
        else if ( s[i] == '9' ) s[i] = '6' ;
    }

    if ( solved ) {
        reverse(s.begin(), s.end()) ;
        if ( check(stoll(s)) ) cout << "yes" ;
        else cout << "no" ;
    }
    else cout << "no" ;

	return 0;
}