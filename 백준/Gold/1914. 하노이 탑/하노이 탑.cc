#include <bits/stdc++.h>

using namespace std ;
typedef unsigned long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

void hanoi(ll n, char start, char temp, char end) {
    if ( n == 1 ) {
        cout << start << " " << end << "\n" ;
        return ;
    }

    hanoi(n-1, start, end, temp) ; // A -> B
    cout << start << " " << end << "\n" ; // A -> C
    hanoi(n-1, temp, start, end) ; // B -> C

}

string bigOper(string a, string b) {
    string temp = "" ;

    int up = 0 ;

    for ( int i = a.size()-1 ; i != -1 ; i -- ) {
        int p = (a[i] - '0') + (b[i] - '0') ;
        temp = to_string((up + p) % 10) + temp ;
        if ( up + p >= 10 ) up = 1 ;
        else up = 0 ;
    }

    if ( up ) temp = '1' + temp ;

    return temp ;
}

string bigMinus(string a) {
    for ( int i = a.size()-1 ; i != -1 ; i -- ) {
        if ( a[i] != '0' ) {
            a[i] = (char)(a[i]-1) ;
            break ;
        }
        else a[i] = '9' ;
    }
    return a ;
}

void count (ll n, string result) {
    
    if ( n == 1 ) {
        cout << bigMinus(result) << "\n" ;
        return ;
    }
    count(n-1, bigOper(result, result)) ;
}


int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    ll k ;
    cin >> k ;

    count(k, "2") ;
    if ( k <= 20 ) hanoi(k, '1', '2', '3') ;

	return 0;
}