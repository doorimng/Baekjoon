#include <iostream>
#include <stdio.h>
#include <stack>
#include <map>
#include <queue>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std ;

int main(void) {
    cin.tie(0)->sync_with_stdio(false) ;

    string a, b ;
    cin >> a >> b ;

    if ( b.size() > a.size() ) cout << "no" ;
    else {
        cout << "go" ;
    }
}