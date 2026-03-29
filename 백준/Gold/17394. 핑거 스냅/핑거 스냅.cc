#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int ans = INF ;

vector <int> v (1000001, 0) ;
vector <int> visited (2000001, 0) ;

queue <pii> q ;
void BFS(int a, int b) {
    while ( !q.empty() ) {
        int temp = q.front().first ;
        int cnt = q.front().second ;
        q.pop() ;

        int next = temp/2 ;

        if ( !visited[next] ) {
            visited[next] = 1 ;

            if ( a <= next && next <= b ) {
                if ( !v[next] ) {
                    ans = min(ans, cnt+1) ;
                    return ;
                }
            }

            q.push({next, cnt+1}) ;
        }

        next = temp/3 ;
        if ( !visited[next] ) {
            visited[next] = 1 ;

            if ( a <= next && next <= b ) {
                if ( !v[next] ) {
                    ans = min(ans, cnt+1) ;
                    return ;
                }
            }

            q.push({next, cnt+1}) ;
        }

        next = temp+1 ;
        if ( !visited[next] && next <= 2000000 ) {
            visited[next] = 1 ;

            if ( a <= next && next <= b ) {
                if ( !v[next] ) {
                    ans = min(ans, cnt+1) ;
                    return ;
                }
            }

            q.push({next, cnt+1}) ;
        }

        next = temp-1 ;
        if ( temp > 0 && !visited[next] ) {
            visited[next] = 1 ;

            if ( a <= next && next <= b ) {
                if ( !v[next] ) {
                    ans = min(ans, cnt+1) ;
                    return ;
                }
            }

            q.push({next, cnt+1}) ;
        }
    }
}

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    v[0] = v[1] = 1 ;
    for ( int i = 2 ; i <= sqrt(1000000) ; i ++ ) {
        if ( !v[i] ) {
            for ( int j = i+i ; j <= 1000000 ; j += i ) {
                v[j] = 1 ;
            }
        }
    }

    while ( t -- ) {
        int n, a, b, check = 0 ;
        cin >> n >> a >> b ;

        while ( !q.empty() ) q.pop() ;
        fill(visited.begin(), visited.end(), 0) ;

        for ( int i = a ; i <= b ; i ++ ) {
            if ( !v[i] ) check = 1 ;
        }

        if ( a <= n && n <= b && !v[n] ) {
            cout << 0 << "\n" ;
            continue ;
        }

        q.push({n, 0}) ;
        BFS(a, b) ;

        if ( !check ) cout << -1 << "\n" ;
        else {
            cout << ans << "\n" ;
            ans = INF ;
        }
    }

    return 0 ;
}