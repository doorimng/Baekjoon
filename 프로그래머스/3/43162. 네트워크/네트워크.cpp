#include <string>
#include <vector>

using namespace std;

int N ;

vector <vector <int>> v ;
vector <int> visited ;

void DFS(int cur) {
    for ( int i = 0 ; i < N ; i ++ ) {
        int temp = v[cur][i] ;
        if ( temp == 0 || i == cur ) continue ;
        if ( visited[i] ) continue ;
        
        visited[i] = 1 ;
        DFS(i) ;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n ;
    
    v = computers ;
    visited.resize(n+1, 0) ;
    
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( !visited[i] ) {
            visited[i] = 1 ;
            DFS(i) ;
            answer ++ ;
        }
    }
    
    return answer;
}
