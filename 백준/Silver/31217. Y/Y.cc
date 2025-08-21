#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    ll DIV = 1000000007, cnt = 0 ;

    vector <vector <int>> v (n+1, vector <int> (0)) ;

    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        v[a].push_back(b) ;
        v[b].push_back(a) ;

        if ( v[a].size() == 3 ) cnt = (cnt + 1) % DIV ;
        else if ( v[a].size() > 3 ) {
            // a를 루트로 하는 두 개의 리프 결정 (nC2)
            cnt += (((v[a].size()-1) * (v[a].size()-2)) / 2) % DIV ;
            cnt %= DIV ;
        }

        if ( v[b].size() == 3 ) cnt = (cnt + 1) % DIV ;
        else if ( v[b].size() > 3 ) {
            // b를 루트로 하는 두 개의 리프 결정 (nC2)
            cnt += (((v[b].size()-1) * (v[b].size()-2)) / 2) % DIV ;
            cnt %= DIV ;
        }
    }

    cout << cnt % DIV ;

    return 0 ;
}