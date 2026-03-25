#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int ans ;
vector <int> visited ;

queue <pair <int, string>> q ;
void BFS() {
    while ( !q.empty() ) {
        int num = q.front().first ;
        string s = q.front().second ;
        q.pop() ;

        // cout << num << " " << s << "\n" ;

        int next = (num*2) % 10000 ;
        if ( !visited[next] ) {
            q.push({next, s+'D'}) ;
            visited[next] = 1 ;
        }

        if ( next == ans ) {
            cout << s+'D' << "\n" ;
            return ;
        }
        
        next = num-1 ;
        if ( next == -1 ) next = 9999 ;

        if ( !visited[next] ) {
            q.push({next, s+'S'}) ;
            visited[next] = 1 ;
        }

        if ( next == ans ) {
            cout << s+'S' << "\n" ;
            return ;
        }

        if ( num <= 999 ) next = num*10 ;
        else next = num%1000 * 10 + num/1000 ;

        if ( !visited[next] ) {
            q.push({next, s+'L'}) ;
            visited[next] = 1 ;
        }

        if ( next == ans ) {
            cout << s+'L' << "\n" ;
            return ;
        }

        next = num%10 * 1000 + num/10 ;

        if ( !visited[next] ) {
            q.push({next, s+'R'}) ;
            visited[next] = 1 ;
        }

        if ( next == ans ) {
            cout << s+'R' << "\n" ;
            return ;
        }
    }
}

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;
    
    int t ;
    cin >> t ;

    visited.resize(10001, 0) ;

    while ( t -- ) {
        int a, b ;
        cin >> a >> b ;

        fill(visited.begin(), visited.end(), 0) ;
        while ( !q.empty() ) q.pop() ;

        ans = b ;
        q.push({a, ""}) ;
        visited[a] = 1 ;
        BFS() ;
    }

    return 0 ;
}