#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <int> v ;
    vector <int> sorted_v ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;

        v.push_back(x) ;
        sorted_v.push_back(x) ;
    }

    sort(sorted_v.begin(), sorted_v.end()) ;

    vector <pii> ans ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( v[i] != sorted_v[i] ) {
            for ( int j = i+1 ; j < n ; j ++ ) {
                if ( v[j] == sorted_v[i] ) {
                    ans.push_back({i, j}) ;
                    for ( int k = i ; k < (j-i)/2 + i+1 ; k ++ ) {
                        int temp = v[j-(k-i)] ;
                        v[j-(k-i)] = v[k] ;
                        v[k] = temp ;
                    }
                }
            }
        }
    }

    cout << ans.size() << "\n" ;
    for ( int i = 0 ; i < ans.size() ; i ++ ) {
        cout << ans[i].first+1 << " " << ans[i].second+1 << "\n" ;
    }

    return 0 ;
}