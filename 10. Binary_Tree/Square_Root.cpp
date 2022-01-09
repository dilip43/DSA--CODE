#include<bits/stdc++.h>
using namespace std;

int mysqrt(int x, int precision) {
	int s = 0, e = x;
	int ans = -1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (1ll * mid * mid == x) {
			ans = mid;
			break;
		}
		if (1ll * mid * mid < x) {
			s = mid + 1;
			ans = mid;
		}
		else {
			e = mid - 1;
		}
	}
	float increment = 0.1;
	for (int i = 0; i < precision; i++) {
		while (ans * ans <= x) {
			ans += increment;
		}
		ans = ans - increment;
		increment = increment / 10;
	}
	return ans;
}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:/input_output/input.txt", "r", stdin);
	freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here


	int n; cin >> n;
	int precision; cin >> precision;
	cout << mysqrt(n, precision);
	return 0;
}
