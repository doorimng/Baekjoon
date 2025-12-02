#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

typedef pair <double, double> pdd ;

struct cmp {
    bool operator()(pdd a, pdd b) {
        if ( abs(a.first) == abs(b.first) ) return a.second > b.second ;
        else return abs(a.first) > abs(b.first) ;
    }
} ;

priority_queue <pdd, vector <pdd>, cmp> pq ;

int main() {

    cin.tie(0)->sync_with_stdio(false) ;

    double x, y, d, t ;
    cin >> x >> y >> d >> t ;

    pq.push({sqrt(x*x+y*y), 0.0}) ;

    while ( true ) {
        if ( abs(pq.top().first) < 1 ) break ;
        
        double temp = pq.top().first ;
        double time = pq.top().second ;
        pq.pop() ;

        if ( t > d ) {
            if ( temp < 0 ) pq.push({temp+1.0, time+1.0}) ;
            else pq.push({temp-1.0, time+1.0}) ;
        }
        else {
            if ( abs(temp) < d*2 ) {
                pq.push({0, time+2*t}) ;
                pq.push({0, time+abs(temp)}) ;
                pq.push({0, time+t+abs(temp-d)}) ;
            }
            else {
                if ( temp < 0 ) {
                    pq.push({temp+1.0, time+1.0}) ;
                    pq.push({temp+d, time+t}) ;
                }
                else {
                    pq.push({temp-1.0, time+1.0}) ;
                    pq.push({temp-d, time+t}) ;
                }
            }
        }
    }

    printf("%.10f", pq.top().second+pq.top().first) ;
    
    return 0 ;
}