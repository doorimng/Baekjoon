#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    if ( n == 0 ) {
        cout << "0\n0 0" ;
        return 0 ;
    }

    map <int, int> mp ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        mp[a] ++ ; 
        mp[b] -- ;
    }

    int cnt = 0, Mx = 0 ;
    for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
        cnt += it->second ;
        Mx = max(Mx, cnt) ;
    }

    cnt = 0 ;
    int check = false ;
    
    cout << Mx << "\n" ;

    for ( auto it = mp.begin() ; it != mp.end() ; it ++ ) {
        cnt += it->second ;
        if ( cnt == Mx && !check ) {
            cout << it->first << " " ;
            check = true ;
        }
        else if ( cnt < Mx && check ) {
            cout << it->first ;
            break ;
        } 
    }
    
    return 0 ;
}