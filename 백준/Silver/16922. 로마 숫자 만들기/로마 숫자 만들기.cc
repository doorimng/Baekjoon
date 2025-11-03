#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, roma[4] = {1, 5, 10, 50} ;

vector <int> visited (1001, 0);
vector <int> temp (1001, 0) ;

set <int> s ;

void btk(int cnt, int start) {
    if ( cnt == n ) {
        int sum = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) sum += temp[i] ;
        s.insert(sum) ;
        return ;
    }

    for ( int i = start ; i < 4 ; i ++ ) {
        visited[i] = 1 ;
        temp[cnt] = roma[i] ;
        btk(cnt+1, i) ;
        visited[i] = 0 ;
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;

    btk(0, 0) ;

    cout << s.size() ;

    return 0 ;
}