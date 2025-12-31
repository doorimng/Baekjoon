#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, num = 1 ;
vector <vector <int>> v ;
unordered_map <string, int> head_visited ;
map <string, int> mp ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    string s ;

    cin >> n >> s ;

    if ( n <= 25 ) cout << s ;
    else {
        string temp = s.substr(11, n-23) ;
        
        int check = false ;
        for ( char c : temp ) {
            if ( c == '.' ) check = true ;
        }

        if ( check ) {
            cout << s.substr(0, 9) << "......" << s.substr(n-10) ;
        }
        else cout << s.substr(0, 11) << "..." << s.substr(n-11) ;
    }
    return 0 ;
}