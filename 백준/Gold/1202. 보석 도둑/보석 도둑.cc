#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, k ;
    cin >> n >> k ;

    vector <pii> jewel ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int m, v ;
        cin >> m >> v ;

        jewel.push_back({m, v}) ;
    }

    sort(jewel.begin(), jewel.end()) ;

    priority_queue <pii> jewels ;
    priority_queue <int, vector <int>, greater<>> bag ;
    for ( int i = 0 ; i < k ; i ++ ) {
        int c ;
        cin >> c ;

        bag.push(c) ;
    }

    ll sum = 0, temp = 0 ;
    while ( !bag.empty() ) {
        int maxSize = bag.top() ;

        for ( int i = temp ; i < n ; i ++ ) {
            int m = jewel[i].first ;
            int v = jewel[i].second ;
            
            if ( m > maxSize ) {
                break ;
            }
            
            jewels.push({v, -m}) ;
            temp = i+1 ;
        }
        
        if ( !jewels.empty() ) {
            sum += jewels.top().first ;
            jewels.pop() ;
        }
        
        bag.pop() ;
    } 

    cout << sum ;

    return 0 ;
}