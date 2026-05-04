#include <bits/stdc++.h>

using namespace std;

int temp;
bool cmp(string a, string b) {
    if ( a[temp] != b[temp] ) return a[temp] < b[temp] ;
    else return a < b ;
}

vector <string> solution(vector <string> v, int n) {

    temp = n ;
    sort(v.begin(), v.end(), cmp) ;

    return v ;
}
