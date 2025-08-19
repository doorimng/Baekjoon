#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct cmp {
    bool operator()(string a, string b) {
        for ( int i = 0 ; i < min(a.size(), b.size()) ; i ++ ) {
            if ( a[i] != b[i] ) {
                if ( a[i] == '-' || b[i] == '-' ) return a[i] < b[i] ;
                else {
                    if ( abs(a[i] - b[i]) == 'a' - 'A' ) return a[i] > b[i] ; // 오름차순


                    if ( a[i] >= 'a' && a[i] <= 'z' ) {
                        if ( b[i] >= 'A' && b[i] <= 'Z') return a[i] > (b[i] + ('a' - 'A')) ;
                    }
                    else {
                        if ( b[i] >= 'a' && b[i] <= 'z' ) return (a[i] + ('a' - 'A')) > b[i] ;
                    }

                    return a[i] > b[i] ;
                    
                }
            }
        }
        return a > b ;
    }
} ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        int n ;
        cin >> n ;

        priority_queue <string, vector <string>, cmp> pq ;

        for ( int i = 0 ; i < n ; i ++ ) {
            string s ;
            cin >> s ;

            pq.push(s) ;
        }

        while ( !pq.empty() ) {
            cout << pq.top() << "\n" ;
            pq.pop() ;
        }
    }

    return 0 ;
}