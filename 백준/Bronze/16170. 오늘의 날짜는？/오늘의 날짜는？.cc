#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main(void){

    cin.tie(0)->sync_with_stdio(false) ;

    time_t timer ;
    struct tm* t ;
    timer = time(NULL) ;
    t = localtime(&timer) ;

    cout << t->tm_year+1900 << "\n" << t->tm_mon+1 << "\n" << t->tm_mday ;

    return 0 ;
}