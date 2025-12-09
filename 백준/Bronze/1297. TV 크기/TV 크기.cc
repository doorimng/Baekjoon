#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    double d, h, w ;
    cin >> d >> h >> w ;

    h /= 100.0 ;
    w /= 100.0 ;

    double x = sqrt(d*d / (h*h+w*w)) ;

    cout << (int)(h*x) << " " << (int)(w*x) ;

    return 0 ;
}