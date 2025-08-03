#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

// yn 이 math.h 상에서 이미 정의되어 있는 듯
double X1, X2, X3, Y1, Y2, Y3 ;

int f() {
    double y = (Y3-Y1) * X2 + (X1-X3) * Y2 - X1*Y3 + Y1*X3 ;

    if ( y == 0 ) return 0 ;
    else if ( y > 0 ) return 1 ; 
    else return -1 ;
}   

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 ;
    int ff = f() ;

    if ( X1 == X3 ) {
        if ( Y1 > Y3 ) { // 첫 좌표가 더 위
            if ( X2 == X1 ) cout << 0 ;
            else if ( X2 > X1 ) cout << -1 ;
            else cout << 1 ; 
        }
        else { // 첫 좌표가 아래
            if ( X2 == X1 ) cout << 0 ;
            else if ( X2 > X1 ) cout << 1 ;
            else cout << -1 ;
        }
    }
    else if ( X1 > X3 ) { // 첫 좌표가 더 오른쪽
        if ( Y1 == Y3 ) {
            if ( Y2 > Y1 ) cout << 1 ;
            else if ( Y2 == Y1 ) cout << 0 ;
            else cout << -1 ;
        }
        else cout << ff ;
    }
    else { // 첫 좌표가 더 왼쪽
        if ( Y1 == Y3 ) {
            if ( Y2 > Y1 ) cout << -1 ;
            else if ( Y2 == Y1 ) cout << 0 ;
            else cout << 1 ;
        }  
        else cout << ff ;
    }

    return 0 ;
}