#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <int>> v ;
vector <int> parent ;
vector <int> visited ;

int lastNode ;

void inorder(int x) {
    if ( v[x][0] > 0 ) inorder(v[x][0]) ;
    lastNode = x ;
    if ( v[x][1] > 0 ) inorder(v[x][1]) ;
}

int n ;
int cnt = 0 ;
void f(int x) {
    if ( x == 0 ) return ;

    cnt ++ ;
    visited[x] = 1 ;

    int left = v[x][0] ;
    int right = v[x][1] ;
    
    if ( left == -1 && right == -1 ) ;
    else if ( left != -1 ) {
        if ( !visited[left] ) return f(left) ;
        else if ( right != -1 && !visited[right] ) return f(right) ;
    }
    else {
        if ( !visited[right] ) return f(right) ;
    }

    if ( x == lastNode ) return ;
    else return f(parent[x]) ;
        
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    cin >> n ;

    v.resize(n+1, vector <int> (2, 0)) ;
    visited.resize(n+1, 0) ;
    parent.resize(n+1, 0) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b, c ;   
        cin >> a >> b >> c ;

        v[a] = {b, c} ;
        if ( b != -1 ) parent[b] = a ;
        if ( c != -1 ) parent[c] = a ;
    }

    inorder(1) ;

    f(1) ;
    cout << cnt-1 ;
    
    return 0 ;
}