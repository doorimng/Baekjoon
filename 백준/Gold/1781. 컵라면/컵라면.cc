#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    ll n ;
    cin >> n ;

    priority_queue <int, vector <int>, greater<int>> pq ;
    vector <pii> v ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        v.push_back({a, b}) ;
    }

    sort(v.begin(), v.end()) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int deadline = v[i].first ;
        int ramen = v[i].second ;

        if ( deadline <= pq.size() ) {
            if ( ramen > pq.top() ) {
                pq.pop() ;
                pq.push(ramen) ;
            }
        }
        else pq.push(ramen) ;
    }

    ll cnt = 0 ;
    while ( !pq.empty() ) {
        cnt += pq.top() ;
        pq.pop() ;
    }

    cout << cnt ;

    return 0 ;
}