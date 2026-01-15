#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <vector <int>> v (26, vector <int> (0)) ; 

    for ( int i = 0 ; i < n ; i ++ ) {
        char c ;
        cin >> c ;

        int k ;
        cin >> k ;

        for ( int j = 0 ; j < k ; j ++ ) {
            char x ;
            cin >> x ;

            v[c-'a'].push_back(x-'a') ;
        }
    }

    string s ;
    cin >> s ;

    for ( int i = 0 ; i < s.size()-1 ; i ++ ) {
        if ( !v[s[i]-'a'].empty() ) {
            int check = 0 ;
            for ( int j = 0 ; j < v[s[i]-'a'].size() ; j ++ ) {
                if ( v[s[i]-'a'][j] == s[i+1]-'a' ) check = 1 ;
            }

            if ( !check ) {
                cout << "no" ;
                return 0 ;
            } 
        }
    }

    cout << "yes" ;
    
    return 0 ;
}