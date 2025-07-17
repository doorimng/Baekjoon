#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <int>> node ;
vector <vector <int>> visited ;

int check = false ;

void DFS(int start, int end) {
    if ( start == end ) {
        check = true ;
        return ;
    }
    
    for ( int i = 0 ; i <= 26 ; i ++ )  {
        if ( node[start][i] == 0 || start == i ) continue ;
        DFS(i, end) ;
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;
    cin.ignore() ;

    node.resize(30, vector <int> (30, 0)) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        getline(cin, s) ;

        node[s[0]-'a'][s[s.size()-1]-'a'] = 1 ;
    }

    int m ;
    cin >> m ;
    cin.ignore() ;

    for ( int i = 0 ; i < m ; i ++ ) {
        string s ;
        getline(cin, s) ;

        check = false ;
        DFS(s[0]-'a', s[s.size()-1]-'a') ;

        if ( check ) cout << "T\n" ;
        else cout << "F\n" ;
    }

    return 0 ;
}