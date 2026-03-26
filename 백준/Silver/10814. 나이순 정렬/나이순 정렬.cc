#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std ;

int main() {

    vector <pair <int, pair <int, string>>> v ; // {나이, {순서, 이름}}

    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i ++ ) {
        int age ;
        string name ;
        cin >> age >> name ;

        v.push_back({age, {i, name}}) ;
    }

    sort(v.begin(), v.end()) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cout << v[i].first << " " << v[i].second.second << "\n" ;
    }
    
    return 0 ;
}