#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct cmp {
    bool operator()(int a, int b) {
        if ( a % 2 && b % 2 ) return a > b ;
        return a%2 > b%2 ;
    }
} ;

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    vector <int> v (3, 0) ;
    for ( int i = 0 ; i < 3 ; i ++ ) cin >> v[i] ;

    int ans = 0, temp ;
    for ( int i = 0 ; i < 3 ; i ++ ) {
        temp = v[i] ;

        if ( ans % 2 == 0 ) {
            if ( temp % 2 ) ans = temp ;
            else ans = max(ans, temp) ;
        }
        else {
            if ( temp % 2 ) ans = max(ans, temp) ; 
        }
    }

    for ( int i = 0 ; i < 2 ; i ++ ) {
        for ( int j = i+1 ; j < 3 ; j ++ ) {
            temp = v[i]*v[j] ;
            if ( ans % 2 == 0 ) {
                if ( temp % 2 ) ans = temp ;
                else ans = max(ans, temp) ;
            }
            else {
                if ( temp % 2 ) ans = max(ans, temp) ; 
            }
        }
    }

    temp = v[0]*v[1]*v[2] ;
    if ( ans % 2 == 0 ) {
        if ( temp % 2 ) ans = temp ;
        else ans = max(ans, temp) ;
    }
    else {
        if ( temp % 2 ) ans = max(ans, temp) ; 
    }
    
    cout << ans ;

	return 0;
}   