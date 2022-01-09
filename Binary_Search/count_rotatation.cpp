#include<bits/stdc++.h>
using namespace std;

int countRotation(int arr[], int size) {
	int start = 0, end = size - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		//4 case over here
		if (mid < end && arr[mid] > arr[mid + 1]) {
			return mid + 1;
		}
		if (mid > start && arr[mid] < arr[mid - 1]) {
			return mid - 1;
		}
		//if element at mid,start and end are equal
	}
}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:/input_output/input.txt", "r", stdin);
	freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here
	int arr[] = {4, 5, 6, 0, 1, 2};
	int size = sizeof(arr) / sizeof(int);
	cout << countRotation(arr, size);


	return 0;
}
