#include<bits/stdc++.h>#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int n, i, m;
	cin >> n >> m;
	int array[n];
	long long int max = 0, h = 0;
	long long int beg, end, mid;
	for (i = 0; i < n; i++) {
		cin >> array[i];
		if (array[i] > max) {
			max = array[i];
		}
	}
	beg = 0; end = max;
	while (beg <= end) {
		mid = (beg + end) / 2;
		cutted = 0;
		for ( i = 0; i < N; ++i ) {
			if ( array[ i ] - mid > 0 ) {
				cutted += array[ i ] - mid;
			}
		}
		if ( cutted > M ) {
			beg = mid + 1;
			if ( mid > h ) {
				h = mid;
			}
		}
		else if ( cutted < M ) {
			end = mid - 1;
		}
		else {
			h = mid;
			break;
		}
	}
	printf( "%lld\n", h );
}



return 0;
}
