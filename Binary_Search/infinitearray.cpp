#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int target, int start, int end) {

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (target < arr[mid]) {
			end = mid - 1;
		}
		else if (target > arr[mid]) {
			start = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int ans(int arr[], int target) {
	// first find the range
	// first start wtih a box of size 2
	int start = 0;
	int end = 1;

	// condition for the target to lie in the range
	while (target > arr[end]) {
		int temp = end + 1;
		end = end + (end - start + 1) * 2;
		start = temp;
	}
	return binarySearch(arr, target, start, end);
}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:/input_output/input.txt", "r", stdin);
	freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here

	int arr[] = { -18, -12, 0, 1, 2, 3, 4, 5, 6, 7, 8};
	int target = 2;
	int ans1 = ans(arr, target);
	cout << ans1;
	return 0;
}
