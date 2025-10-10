#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int Palindrome(string s) {
    int check = 1 ;

    for ( int i = 0 ; i < s.size()/2 ; i ++ ) {
        if ( s[i] != s[s.size()-1-i] ) check = 0 ;
    }

    return check ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, cnt = 0 ;
    cin >> n ;

    vector <string> v ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        cnt += Palindrome(s) ;
    }

    cout << cnt * (cnt-1) ;

    return 0 ;
}