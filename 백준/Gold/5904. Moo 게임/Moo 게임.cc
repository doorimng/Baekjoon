#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

string s = "moo" ;

void moo(int n, int temp, int cur) {
    if ( n <= 3 ) {
        cout << s[n-1] ;
        return ;
    }

    if ( n > cur ) moo(n, temp+1, cur*2 + temp+1) ;
    else { 
        if ( n > (cur - temp) / 2 && n <= (cur - temp) / 2 + temp ) {
            if ( n == (cur - temp) / 2 + 1 ) cout << 'm' ;
            else cout << 'o' ;
        }
        else {
            if ( n > (cur - temp) / 2 + temp ) 
                moo((cur - temp) / 2 - (cur - n), temp-1, (cur - temp) / 2) ;
            else moo(n, temp-1, (cur - temp) / 2) ;
        }
    }

}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;
    
    moo(n, 3, 3) ;

    return 0 ;
}