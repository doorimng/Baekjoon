#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
   
    int n ;
    cin >> n ;

    string s = "" ;

    for ( int i = 0 ; i < n ; i ++ ) {
        char c ;
        cin >> c ;

        s += c ;
    }

    string t = "" ;
    int l = 0, r = n-1 ;
    while ( l <= r ) {
        if ( s[l] == s[r] ) {
        
            int i = l, j = r ;
            while ( s[i] == s[j] ) {
                if ( i+1 >= j ) break ;
                i ++ ;
                j -- ;
            }

            if ( s[i] < s[j] ) t += s[l++] ;
            else t += s[r--] ;
        }
        else if ( s[l] < s[r] ) t += s[l++] ;
        else t += s[r--] ;
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        cout << t[i-1] ;
        if ( i % 80 == 0 ) cout << "\n" ;
    }

    return 0 ;
}