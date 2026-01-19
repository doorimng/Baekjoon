#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct Trie {
    Trie* nextNode[26] ;
    int finish ;

    Trie() {
        memset(nextNode, 0, sizeof(nextNode)) ;
        finish = 0 ;
    } 
    ~Trie() {
        for ( int i = 0 ; i < 26 ; i ++ ) {
            if ( nextNode[i] ) delete nextNode[i] ;
        }
    }

    void Insert(const string& s, int indx) {
        if ( indx == s.size() ) finish ++ ;
        else {
            int next = s[indx]-'a' ;

            if ( nextNode[next] == nullptr ) {
                nextNode[next] = new Trie ;
            }
            nextNode[next] -> Insert(s, indx+1) ;
        }
    }

    int Find(const string& s, int indx) {
        if ( indx == s.size() ) return finish+1 ;

        int next = s[indx]-'a' ;
        if  ( nextNode[next] == nullptr ) return 0 ;

        return nextNode[next] -> Find(s, indx+1) ;
    }
} ;

int main() {
    
    cin.tie(0)->sync_with_stdio(false) ;

    int n ;
    cin >> n ;

    Trie trie ;

    for ( int i = 0 ; i < n ; i ++ ) {
        string s ;
        cin >> s ;

        int res = trie.Find(s, 0) ;

        if ( res == 0 ) {
            string temp = "" ;
            for ( int i = 0 ; i < s.size() ; i ++ ) {
                temp += s[i] ;
                if ( !trie.Find(temp, 0) ) {
                    cout << temp ;
                    break ;
                }
            }
        }
        else if ( res == 1 ) cout << s ;
        else cout << s << res ;

        cout << "\n" ;

        trie.Insert(s, 0) ;
    }

    return 0 ;
}