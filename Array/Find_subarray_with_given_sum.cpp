#include<bits/stdc++.h>
using namespace std;

void subArraysum(int arr[], int n, int sum) {
	unordered_map<int, int> map;
	int curr_sum = 0;
	for (int i = 0; i < n; i++) {
		curr_sum += arr[i];
		if (curr_sum == sum) {
			cout << "sum found between index" << 0 << "to" << i << endl;
			return;
		}
		if (map.find(curr_sum - sum) != map.end()) {
			cout << "sum found between indexes" << map[curr_sum - sum] + 1 << "to" << i << endl;
			return;
		}
		map[curr_sum] = i;
	}
	cout << "no subarray with given sum exists";
}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:/input_output/input.txt", "r", stdin);
	freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here

	int arr[] = { -3, 2, 3, 1, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	subArraysum(arr, n, sum);

	return 0;
}
