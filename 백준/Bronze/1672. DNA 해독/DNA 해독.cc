#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;  
    string s ;
    cin >> s ;

    vector <vector <char>> DNA = {
        {'A', 'C', 'A', 'G'}, 
        {'C', 'G', 'T', 'A'},
        {'A', 'T', 'C', 'G'},
        {'G', 'A', 'G', 'T'}
    } ;

    while ( s.size() != 1 ) {
        n = s.size()-1 ;

        int y, x ;

        if ( s[n] == 'A' ) x = 0 ;
        if ( s[n] == 'G' ) x = 1 ;
        if ( s[n] == 'C' ) x = 2 ;
        if ( s[n] == 'T' ) x = 3 ;

        if ( s[n-1] == 'A' ) y = 0 ;
        if ( s[n-1] == 'G' ) y = 1 ;
        if ( s[n-1] == 'C' ) y = 2 ;
        if ( s[n-1] == 'T' ) y = 3 ;

        s.pop_back() ; s.pop_back() ;
        s.push_back(DNA[y][x]) ;
    }
    
    cout << s ;

    return 0 ;
}