#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <int> v ;
vector <int> visited ;
vector <int> moved ; // [이동횟수]

int check = 0 ;
void DFS(int n, int temp) {

    while ( true ) {
        if ( visited[temp] == n ) {
            if ( temp != n ) check -= moved[temp] ;
            break ;
        }
        else if ( visited[temp] ) {
            check = 0 ;
            break ;
        }

        moved[temp] = check++ ;
        visited[temp] = n ;
        temp = v[temp] ;
    }

    return ;
}

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        int n ;
        cin >> n ;

        v.clear() ;
        visited.clear() ;
        moved.clear() ;
        v.resize(n+1, 0) ;
        visited.resize(n+1, 0) ;
        moved.resize(n+1, 0) ;

        for ( int i = 1 ; i <= n ; i ++ ) {
            cin >> v[i] ;
        }

        int cnt = n ;
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( !visited[i] ) {
                DFS(i, i) ;
                cnt -= check ;
                check = 0 ;
            }
        }
        cout << cnt << "\n" ;
    }

    return 0 ;
}