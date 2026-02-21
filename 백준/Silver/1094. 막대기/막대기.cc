#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int x, sum = 64 ;
    cin >> x ;

    priority_queue <int, vector <int>, greater<>> pq ;
    pq.push(64) ;

    while ( true ) {
        if ( sum <= x ) break ;

        int temp = pq.top() ;
        pq.pop() ;
        pq.push(temp/2) ;

        if ( sum - temp/2 >= x ) sum -= temp/2 ;
        else pq.push(temp/2) ;

    }

    cout << pq.size() ; 
    
    return 0 ;
}