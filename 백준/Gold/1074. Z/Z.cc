#include <iostream>
#include <stdio.h>
#include <string.h>
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
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <cctype>
#include <deque>
#include <climits>
#include <iomanip>
#include <sstream>

using namespace std ;
typedef long long ll ;

ll n, r, c, cnt = 0 ;

void Z(ll y, ll x, ll k) {

    if ( k == 1 ) {
        if ( y == r && x == c ) cout << cnt ;
        cnt ++ ;
        return ;
    }

    if (r < y + k/2 && c < x + k/2) {
        Z(y, x, k/2);
    }
    else if (r < y + k/2 && c >= x + k/2) {
        cnt += (k/2)*(k/2);
        Z(y, x + k/2, k/2);
    }
    else if (r >= y + k/2 && c < x + k/2) {
        cnt += (k/2)*(k/2)*2;
        Z(y + k/2, x, k/2);
    } 
    else {
        cnt += (k/2)*(k/2)*3;
        Z(y + k/2, x + k/2, k/2);
    }
    
}

int main() {

    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> r >> c ;

    n = (ll) pow(2, n) ;

    Z(0, 0, n) ;
    
    return 0 ;
}