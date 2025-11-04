#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int q, dir = 0 ; // dir : 동0 남1 서2 북3 
    cin >> q ;

    deque <char> dq ;
    int ball = 0, wall = 0 ;

    while ( q -- ) {
        string s ;
        cin >> s ;

        if ( s == "pop" ) {
            if ( !dq.empty() ) {
                if ( dq.front() == 'b' ) ball -- ;
                if ( dq.front() == 'w' ) wall -- ;
                dq.pop_front() ;
            }
        }
        else {
            char c ;
            cin >> c ;

            if ( s == "push" ) {
                if ( c == 'b' ) {
                    ball ++ ;
                    dq.push_back(c) ;
                }
                
                if ( c == 'w' ) {
                    wall ++ ;
                    dq.push_back(c) ;
                }
            }

            if ( s == "rotate" ) {
                if ( c == 'l' ) dir = (dir + 3) % 4 ;
                if ( c == 'r' ) dir = (dir + 1) % 4 ;
            }

            if ( s == "count" ) {
                if ( c == 'b' ) cout << ball << "\n" ;
                if ( c == 'w' ) cout << wall << "\n" ;
            }
        }

        if ( dir == 1 ) {
            while ( !dq.empty() && dq.front() != 'w' ) {
                dq.pop_front() ;
                ball -- ;
            }
        }
        if ( dir == 3 ) {
            while ( !dq.empty() && dq.back() != 'w' ) {
                dq.pop_back() ;
                ball -- ;
            }
        }

    }

    return 0 ;
}