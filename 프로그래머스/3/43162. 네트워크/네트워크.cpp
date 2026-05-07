#include <iostream>
#include <vector>

using namespace std ;

int N ;

vector <vector <int>> v ;
vector <int> visited ;

void DFS(int n) {
    for ( int i = 0 ; i < N ; i ++ ) {
        int temp = v[n][i] ;
        if ( N == n || temp == 0 ) continue ;

        if ( visited[i] ) continue ;
        
        visited[i] = 1 ;
        DFS(i) ;
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> computers) {
    int answer = 0 ;
    N = n ;

    v = computers ;
    visited.clear() ;
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