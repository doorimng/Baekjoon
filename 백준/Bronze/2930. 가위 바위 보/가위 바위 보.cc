#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int r, n ;
string s ;
vector <string> friends ;

int MaxScore() {

    int score = 0 ;
    
    for ( int i = 0 ; i < r ; i ++ ) {
        int R = 0, S = 0, P = 0 ;
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( friends[j][i] == 'R') R ++ ;
            else if ( friends[j][i] == 'S' )  S ++ ;
            else P ++ ;
        }
        
        int r_score = R * 1 + S * 2 ;
        int s_score = S * 1 + P * 2 ;
        int p_score = P * 1 + R * 2 ;

        score += max({r_score, s_score, p_score}) ;
    }
    
    return score ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> r >> s >> n ;

    int score = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        string t ;
        cin >> t ;

        for ( int j = 0 ; j < r ; j ++ ) {
            if ( s[j] == t[j] ) score += 1 ;
            else if ( s[j] == 'R' && t[j] == 'S' ) score += 2 ;
            else if ( s[j] == 'S' && t[j] == 'P' ) score += 2 ;
            else if ( s[j] == 'P' && t[j] == 'R' ) score += 2 ;  
        }

        friends.push_back(t) ;
    }


    cout << score << "\n" << MaxScore() ;

    return 0 ;
}