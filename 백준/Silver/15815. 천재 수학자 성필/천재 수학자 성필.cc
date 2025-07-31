#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    string s ;
    cin >> s ;

    stack <int> num ;

    for ( int i = 0 ; i < s.size() ; i ++ ) {
        if ( s[i] >= '0' && s[i] <= '9' ) num.push(s[i]-'0') ;
        else {
            int a = num.top() ;
            num.pop() ;
            int b = num.top() ;
            num.pop() ;

            if ( s[i] == '+' ) num.push(b+a) ;
            else if ( s[i]== '-' ) num.push(b-a) ;
            else if ( s[i] == '*' ) num.push(b*a) ;
            else num.push(b/a) ;
        }
    }

    cout << num.top() ;

    return 0 ;
}