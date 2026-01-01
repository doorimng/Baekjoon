#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int n, indx = 1 ;
vector <vector <int>> v (15001, vector <int> (0)) ;
// unordered_map <string, int> head_visited ; 
map <string, int> head_visited ;
// vector <int> head_visited (15001, 0) ;
// map <string, int> mp ;
vector <string> foodList (15001) ;

vector <int> visited (15001, 0) ;

struct cmp {
    bool operator()(int a, int b) {
        return foodList[a] < foodList[b] ;
    }
} ;

void DFS(int n, string step) {
    for ( int x : v[n] ) {
        if ( !visited[x] ) {
            // visited[x] = 1 ;
            visited[x] = 1 ;
            // cout << x << " " ;
            cout << step << foodList[x] << "\n" ;
            DFS(x, step+"--") ;
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    // 14725 
    // 이렇게 풀면 안돼

    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int k ;
        cin >> k ;

        vector <int> temp ;

        for ( int j = 0 ; j < k ; j ++ ) {
            string s ;
            cin >> s ;

            temp.push_back(indx) ;
            foodList[indx++] = s ;
        }

        int head = head_visited[foodList[temp[0]]] ;
        if ( head ) {
            for ( int j = 1 ; j < k ; j ++ ) {
                int check = 0 ;
                for ( int x : v[head] ) {
                    if ( foodList[x] == foodList[temp[j]] ) {
                        head = x ;
                        check = 1 ;
                        break ; 
                    }
                }
                if ( !check ) {
                    v[head].push_back(temp[j]) ;
                    head = temp[j] ;
                }
            }
        }
        else {
            head_visited[foodList[temp[0]]] = temp[0] ;
            visited[temp[0]] = 1 ;

            for ( int j = 1 ; j < k ; j ++ ) {
                v[temp[j-1]].push_back(temp[j]) ;
            }
        }
    }

    // cout << '\n' ;
    // for ( int i = 1 ; i < indx ; i ++ ) {
    //     cout << i << ": " ;
    //     for ( int j = 0 ; j < v[i].size() ; j ++ ) {
    //         cout << v[i][j] << " " ;
    //     } 
    //     cout << "\n" ;
    // }
    // cout << '\n' ;

    vector <pair<string, int>> head ;

    for ( int i = 1 ; i <= indx ; i ++ ) {
        if ( head_visited[foodList[i]] && visited[i] ) {
            head.push_back({foodList[i], i}) ;
        }
    } 

    for ( int i = 1 ; i < indx ; i ++ ) {
        sort(v[i].begin(), v[i].end(), cmp()) ;
    }

    sort(head.begin(), head.end()) ;

    for ( int i = 0 ; i < head.size() ; i ++ ) {
        visited[head[i].second] = 1 ;
        cout << head[i].first << "\n" ;
        DFS(head[i].second, "--") ;
    }
    return 0 ;
}
