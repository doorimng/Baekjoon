#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int isPow(int n) {
    int cnt = 0, nn = n ;
    while ( nn > 1 ) {
        nn /= 2 ;
        cnt ++ ;
    }

    if ( (int) pow(2, cnt) == n ) return 1 ;
    else return 0 ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int a, b, c ;
    cin >> a >> b >> c ;

    for ( int i = -100 ; i <= 100 ; i ++ ) {
        for ( int j = -100 ; j <= 100 ; j ++ ) {
            if ( a * i * i + b * i + c == 0 && a * j * j + b * j + c == 0 ) {
                if ( i == j ) continue ;

                if ( i != 1 && j != 1 && isPow(i) && isPow(j) ) {
                    cout << "이수근" ;
                    return 0 ;
                }
                else {
                    cout << "정수근" ;
                    return 0 ;
                }
            }
        }
    }

    cout << "둘다틀렸근" ;
    return 0 ;
}