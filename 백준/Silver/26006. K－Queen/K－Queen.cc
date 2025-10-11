#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1} ;
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1} ;

int visited[9] = {0, } ;

int n, k ;
pii white ;
vector <pii> black ;
vector <pii> white_move ;

int check(pii king) {
    for ( int i = 0 ; i < k ; i ++ ) {
        if ( king.first == black[i].first  
                || king.second == black[i].second 
                || king.first - king.second == black[i].first - black[i].second
                || king.first + king.second == black[i].first + black[i].second )
            return 1 ;
    }
    return 0 ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n >> k ;

    cin >> white.first >> white.second ;

    for ( int i = 0 ; i < k ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        black.push_back({a, b}) ;
    }

    if ( check(white) ) visited[8] = 1 ;
    
    for ( int i = 0 ; i < 8 ; i ++ ) {
        int yy = white.first + dy[i] ;
        int xx = white.second + dx[i] ;

        if ( yy <= 0 || yy > n || xx <= 0 || xx > n ) continue ;

        if ( check({yy, xx}) ) visited[i] = 1 ;
           
    }

    for ( int i = 0 ; i < 8 ; i ++ ) {
        int yy = white.first + dy[i] ;
        int xx = white.second + dx[i] ;

        if ( !(yy <= 0 || yy > n || xx <= 0 || xx > n)
            && !visited[i] ) {
            if ( visited[8] ) cout << "CHECK" ;
            else cout << "NONE" ;
            return 0 ;
        }
    }

    if ( visited[8] ) cout << "CHECKMATE" ;
    else cout << "STALEMATE" ;

    return 0 ;
}