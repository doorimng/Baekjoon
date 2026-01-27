#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <int> parent ;
vector <int> cnt ;

int find(int x) {
    if ( parent[x] == -1 ) {
        return x ;
    }
    else {
        parent[x] = find(parent[x]) ;
        return parent[x] ;
    }
}

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        int n ;
        cin >> n ;

        parent.clear() ;
        cnt.clear() ;
        parent.resize(200001, -1) ;
        cnt.resize(200001, 1) ;

        map <string, int> mp ;
        int indx = 1 ;

        for ( int i = 0 ; i < n ; i ++ ) {
            string a, b ;
            cin >> a >> b ;

            if ( !mp[a] ) mp[a] = indx ++ ;
            if ( !mp[b] ) mp[b] = indx ++ ;

            int aa = find(mp[a]) ;
            int bb = find(mp[b]) ;

            if ( aa != bb ) {
                parent[bb] = aa ;
                cnt[aa] += cnt[bb] ;
            }
            
            cout << max(cnt[aa], cnt[bb]) << "\n" ;
        }
    }
	return 0;
}