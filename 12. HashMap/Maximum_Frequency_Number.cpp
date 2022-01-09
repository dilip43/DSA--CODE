#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int maxFrequency(int *arr, int size) {
	unordered_map<int, int>seen;
	for (int i = 0; i < size; i++) {
		if (seen.count(arr[i]) > 0) {
			seen[arr[i]]++;
		}
		else
			seen[arr[i]] = 1;
	}
	int max = INT_MIN;
	int ans = 0;

	for (int i = 0; i < size; i++) {
		if (seen.count(arr[i]) > max) {
			max = seen[arr[i]];
			ans = arr[i];
		}
	}
	return ans;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9};
	cout << maxFrequency(arr, 11);
}