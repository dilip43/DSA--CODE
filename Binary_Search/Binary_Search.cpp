#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int target, int size) {
	int start = 0;
	int end = size - 1;

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

int orderAgnosticBS(int arr[], int target, int start, int end) {
	bool isAsc = arr[start] < arr[end];
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		if (isAsc) {
			if (target < arr[mid]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		else {
			if (target > arr[mid]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return -1;
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
	int target = 8;
	int size = sizeof(arr) / sizeof(int);
	int ans = binarySearch(arr, target, size);
	cout << ans;
	return 0;
}



