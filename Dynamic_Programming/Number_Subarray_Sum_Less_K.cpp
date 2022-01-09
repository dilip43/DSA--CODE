#include <bits/stdc++.h>
using namespace std;

int countSubarray(int arr[], int n, int k)
{
	int start = 0, end = 0, count = 0, sum = arr[0];
	while (start < n && end < n) {
		if (sum < k) {
			end++;

			if (end >= start)
				count += end - start;

			if (end < n)
				sum += arr[end];
		}
		else {
			sum -= arr[start];
			start++;
		}
	}
	return count;
}

int main() {
	int array[] = {1, 11, 2, 3, 15};
	int k = 10;
	int size = sizeof(array) / sizeof(array[0]);
	int count = countSubarray(array, size, k);
	cout << count << endl;
}