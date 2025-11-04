#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, l ;
    cin >> n >> l ;

    deque <pii> dq ; // {원소, 인덱스}

    for ( int i = 1 ; i <= n ; i ++ ) {
        int x ;
        cin >> x ;

        if ( !dq.empty() ) {
            if ( dq.front().second < i-l+1 ) dq.pop_front() ;
        }

        while ( !dq.empty() && x < dq.back().first ) dq.pop_back() ;

        dq.push_back({x, i}) ;
        cout << dq.front().first << " " ;
    }

    return 0 ;
}