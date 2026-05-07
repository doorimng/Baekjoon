#include <string>
#include <vector>
#include <queue>

using namespace std;

int Mx = 0 ;

vector <vector <int>> v ;
vector <int> visited ;

queue <int> q ;
void BFS() {
    while ( !q.empty() ) {
        int temp = q.front() ;
        q.pop() ;

        for ( int x : v[temp] ) {
            if ( !visited[x] ) {
                visited[x] = visited[temp] + 1 ;
                Mx = max(Mx, visited[x]) ;
                q.push(x) ;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    Mx = 0 ;

    v.resize(n+1, vector <int> (0)) ;
    visited.resize(n+1, 0) ;

    for ( int i = 0 ; i < edge.size() ; i ++ ) {
        int a = edge[i][0] ;
        int b = edge[i][1] ;

        v[a].push_back(b) ;
        v[b].push_back(a) ;
    }

    q.push(1) ;
    visited[1] = 1 ;
    BFS() ;

    for ( int x : visited ) {
        if ( x == Mx ) answer ++ ;
    }

    return answer;
}