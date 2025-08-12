#include <iostream>
#include <stdio.h>
#include <stack>
#include <map>
#include <queue>
#include <math.h>
#include <algorithm>
#include <set>
#include <string>
#include <vector> 
#include <unordered_map>
#include <ctime> 

using namespace std ;
typedef long long ll ;

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;
    // ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL) ;

    int n ;
    cin >> n ;

    int building[n] ;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> building[i] ;
    }

    ll sum = 0 ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = i+1 ; j < n ; j ++ ) {
            if ( building[i] <= building[j] ) break ;
            else sum ++ ;
        }
    }

    cout << sum ;


    return 0;
}