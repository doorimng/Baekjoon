#include <bits/stdc++.h>

using namespace std ;

vector <string> solution(vector <string> v, int n) {
    vector <pair <char, string>> temp ;

    for ( string s: v ) {
        temp.push_back({s[n], s}) ;
    }
    
    sort(temp.begin(), temp.end()) ;
    
    vector <string> ans;
    for ( int i = 0 ; i < temp.size() ; i ++ ) {
        ans.push_back(temp[i].second) ;
    }

    return ans;
}