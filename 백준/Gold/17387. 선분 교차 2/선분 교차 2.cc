#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

struct info {
    ll y ;
    ll x ;
} ;

ll CCW(info a, info b, info c) {
    ll temp = (a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y) ;

    if ( temp > 0 ) return 1 ; // 반시계
    else if ( temp < 0 ) return -1 ; // 시계
    else return 0 ; // 일직선
}

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    info a, b, c, d ;
    cin >> a.x >> a.y >> b.x >> b.y ;
    cin >> c.x >> c.y >> d.x >> d.y ;

    if ( CCW(a, b, c) * CCW(a, b, d) < 0 ) {
        if ( CCW(c, d, a) * CCW(c, d, b) < 0 ) {
            cout << 1 ;
            return 0 ;
        }
    }

    if ( CCW(a, b, c) == 0 ) {
        if ( min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) 
            && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y) ) {
            cout << 1 ;
            return 0 ;
        }
    }

    if ( CCW(a, b, d) == 0 ) {
        if ( min(a.x, b.x) <= d.x && d.x <= max(a.x, b.x) 
            && min(a.y, b.y) <= d.y && d.y <= max(a.y, b.y) ) {
            cout << 1 ;
            return 0 ;
        }
    }

    if ( CCW(c, d, a) == 0 ) {
        if ( min(c.x, d.x) <= a.x && a.x <= max(c.x, d.x) 
            && min(c.y, d.y) <= a.y && a.y <= max(c.y, d.y) ) {
            cout << 1 ;
            return 0 ;
        }
    }

    if ( CCW(c, d, b) == 0 ) {
        if ( min(c.x, d.x) <= b.x && b.x <= max(c.x, d.x) 
            && min(c.y, d.y) <= b.y && b.y <= max(c.y, d.y) ) {
            cout << 1 ;
            return 0 ;
        }
    }

    cout << 0 ;
    return 0 ;
}