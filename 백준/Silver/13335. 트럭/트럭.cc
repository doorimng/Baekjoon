#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, w, l ;
    cin >> n >> w >> l ;
    
    queue <int> q ; 
    for ( int i = 1 ; i < w ; i ++ ) q.push(0) ;
    vector <int> truck (n+1, 0) ;

    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> truck[i] ;
        truck[i] += truck[i-1] ;
    }

    int i = 1, cnt = 0 ;
    while ( i <= n ) {
        if ( i == 1 ) q.push(truck[i++]) ;
        else {
            if ( truck[i] - q.front() > l ) { // 최대하중 넘을 경우
                q.push(q.back()) ;
                q.pop() ;
            }
            else {
                q.push(truck[i++]) ;
                q.pop() ;
            }
        }
        cnt ++ ;
    }

    while ( !q.empty() ) {
        q.pop() ;
        cnt ++ ;
    }

    cout << cnt ;

    return 0 ;
}