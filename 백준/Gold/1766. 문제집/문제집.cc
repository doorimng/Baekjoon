#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

vector <vector <int>> v ;
vector <int> parent ;
vector <int> solved ;

struct info {
    int num ; // 문제 번호
    int parentCnt ; // 부모 개수
} ;

struct cmp {
    bool operator()(info a, info b) {
        if ( a.parentCnt == b.parentCnt ) return a.num > b.num ;
        else return a.parentCnt > b.parentCnt ;
    }
} ;

priority_queue <info, vector <info>, cmp> pq ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    v.resize(n+1, vector <int> (0)) ;
    parent.resize(n+1, 0) ;
    solved.resize(n+1, 0) ;

    for ( int i = 0 ; i < m ; i ++ ) {
        int a, b ;
        cin >> a >> b ;

        v[a].push_back(b) ;
        parent[b] ++ ;
    }

    for ( int i = 1 ; i <= n ; i ++ ) {
        // 부모 없는 상태면 바로 풀 수 있음 표시
        if ( !parent[i] ) {
            pq.push({i, 0}) ;
        }
    }

    while ( !pq.empty() ) {
        info temp = pq.top() ;
        int num = temp.num ;

        if ( !solved[num] ) cout << num << " " ;
        solved[num] = 1 ;
        pq.pop() ;

        for ( int x : v[num] ) {
            if ( !solved[x] ) {
                pq.push({x, --parent[x]}) ;
            }
        }
    }

    return 0 ;
}