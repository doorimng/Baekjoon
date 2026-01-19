#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct cmp {
    bool operator()(string a, string b) {
        // if ( a.size() == b.size() ) ;
        return a.size() > b.size() ;
    }
} ;

struct Trie {
    Trie* nextNode[10] ;
    bool finish ;

    Trie() {
        memset(nextNode, 0, sizeof(nextNode)) ;
        finish = false ;
    } 
    ~Trie() {
        for ( int i = 0 ; i < 10 ; i ++ ) {
            if ( nextNode[i] ) delete nextNode[i] ;
        }
    }

    void Insert(const string& s, int indx) {
        if ( indx == s.size() ) finish = true ;
        else {
            int next = s[indx]-'0' ;

            if ( nextNode[next] == nullptr ) {
                nextNode[next] = new Trie ;
            }
            nextNode[next] -> Insert(s, indx+1) ;
        }
    }

    bool Find(const string& s, int indx) {
        if ( indx == s.size() ) return true ;

        int next = s[indx]-'0' ;
        if  ( nextNode[next] == nullptr ) return false ;
        return nextNode[next] -> Find(s, indx+1) ;
    }
} ;

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int t ;
    cin >> t ;

    while ( t -- ) {
        int n ;
        cin >> n ;
        
        vector <string> v ;
        Trie trie ;

        for ( int i = 0 ; i < n ; i ++ ) {
            string s ;
            cin >> s ;

            v.push_back(s) ;
        }

        sort(v.begin(), v.end(), cmp()) ;

        int check = 1 ;
        trie.Insert(v[0], 0) ;
        for ( int i = 1 ; i < n ; i ++ ) {
            if ( trie.Find(v[i], 0) ) {
                check = 0 ;
                break ;
            }
            trie.Insert(v[i], 0) ;
        }

        cout << ((check) ? "YES\n" : "NO\n") ;
    }

    return 0 ;
}