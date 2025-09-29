#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n ;
vector <vector <int>> v ;

int col_visit[200] ;
int downright_visit[200] ;
int upright_visit[200] ;

int num = 0 ;
void btk(int row) {
    if ( row == n ) {
        num ++ ;
        return ;
    }
    else {
        for ( int col = 0 ; col < n ; col ++ ) {
            if ( !col_visit[col] && !downright_visit[row - col + n] && !upright_visit[row + col] ) {
                col_visit[col] = 1 ;
                downright_visit[row - col + n] = 1 ;
                upright_visit[row + col] = 1 ;

                btk(row+1) ;

                col_visit[col] = 0 ;
                downright_visit[row - col + n] = 0 ;
                upright_visit[row + col] = 0 ;
            }
        }
    }
}


int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;

    v.resize(n+1, vector <int> (n+1, 0)) ;

    btk(0) ;

    cout << num ;

    return 0 ;
}