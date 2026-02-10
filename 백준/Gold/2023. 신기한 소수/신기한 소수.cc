#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int isPrime(string s) {
    int n = stoi(s) ;

    if ( n % 2 == 0 ) return 0 ;

    for ( int i = 3 ; i < n ; i += 2 ) {
        if ( n % i == 0 ) return 0 ;
    }

    return 1 ;
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    vector <string> vv = {"2", "3", "5", "7"} ;
    vector <string> temp ;

    if ( n == 1 ) {
        cout << "2\n3\n5\n7" ;
        return 0 ;
    }

    for ( int i = 0 ; i < vv.size() ; i ++ ) {
        for ( char j = '1' ; j <= '9' ; j ++ ) {
            string ss = vv[i]+j ;
            if ( isPrime(ss) ) temp.push_back(ss) ;
        }

        // if ( vv[i].size() == n ) break ;
        
        if ( i == vv.size()-1 ) {
            if ( vv[i].size() == n-1 ) {
                for ( int j = 0 ; j < temp.size() ; j ++ ) {
                    cout << temp[j] << "\n" ;
                }
                break ;
            }
            vv = temp ;
            temp.clear() ;
            i = -1 ;
        }
    }

    return 0 ;
}