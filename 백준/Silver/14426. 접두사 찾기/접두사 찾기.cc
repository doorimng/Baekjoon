#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct Trie {
    Trie* nextNode[26] ;
    bool finish ;

    Trie() {
        memset(nextNode, 0, sizeof(nextNode)) ;
        finish = false ;
    } 
    ~Trie() {
        for ( int i = 0 ; i < 26 ; i ++ ) {
            if ( nextNode[i] ) delete nextNode[i] ;
        }
    }

    void Insert(const string& s, int indx) {
        if ( indx == s.size() ) finish = true ;
        else {
            int next = s[indx]-'a' ;

            if ( nextNode[next] == nullptr ) {
                nextNode[next] = new Trie ;
            }
            nextNode[next] -> Insert(s, indx+1) ;
        }
    }

    bool Find(const string& s, int indx) {
        if ( indx == s.size() ) return true ;

        int next = s[indx]-'a' ;
        if  ( nextNode[next] == nullptr ) return false ;
        return nextNode[next] -> Find(s, indx+1) ;
    }
} ;

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n, m ;
    cin >> n >> m ;

    Trie trie ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;
        
        trie.Insert(s, 0) ;
    }

    int cnt = 0 ;
    for ( int i = 0 ; i < m ; i ++ ) {
        string s ;
        cin >> s ;

        if ( trie.Find(s, 0) ) cnt ++ ;
    }

    cout << cnt ;

    return 0 ;
}