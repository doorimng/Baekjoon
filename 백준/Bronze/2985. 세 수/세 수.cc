#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int a, b, c ;
    cin >> a >> b >> c ;

    if ( a + b == c ) printf("%d+%d=%d", a, b, c) ; 
    else if ( a - b == c ) printf("%d-%d=%d", a, b, c) ; 
    else if ( a * b == c ) printf("%d*%d=%d", a, b, c) ; 
    else if ( a / b == c ) printf("%d/%d=%d", a, b, c) ; 

    else if ( a == b + c ) printf("%d=%d+%d", a, b, c) ;
    else if ( a == b - c ) printf("%d=%d-%d", a, b, c) ;
    else if ( a == b * c ) printf("%d=%d*%d", a, b, c) ;
    else if ( a == b / c ) printf("%d=%d/%d", a, b, c) ;

    return 0 ;
}