#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
typedef pair <int, int> pii ;
#define INF INT_MAX

int main() {

    cin.tie(0)->sync_with_stdio(false) ;
	
	int n, nn ;
	cin >> n ;
	nn = n ;

	while ( n > 1 ) {
		cout << n << " bottles of beer on the wall, " << n << " bottles of beer.\n" ;
		if ( n-1 == 1 ) cout << "Take one down and pass it around, " << --n << " bottle of beer on the wall.\n\n" ;
		else cout << "Take one down and pass it around, " << --n << " bottles of beer on the wall.\n\n" ;
	}

	if ( n == 1 ) {
		cout << "1 bottle of beer on the wall, 1 bottle of beer.\n" ;
		cout << "Take one down and pass it around, no more bottles of beer on the wall.\n\n" ;

		cout << "No more bottles of beer on the wall, no more bottles of beer.\n" ;
		if ( nn > 1 ) cout << "Go to the store and buy some more, "<< nn << " bottles of beer on the wall." ;
		else cout << "Go to the store and buy some more, "<< nn << " bottle of beer on the wall." ;
	}

    return 0 ;
}