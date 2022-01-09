#include<bits/stdc++.h>
using namespace std;

int getMedian(int ar1, ar2, int n) {
	if (n <= 0)
		return -1;
	if (n == 1)
		return (ar1[0] + ar2[0]) / 2;
	if (n == 2)
		return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

	int m1 = median(ar1, n);
	int m2 = median(ar2, n);
	if (m1 == m2) return m1;
	if (m1 < m2) {

	}
}

int median(int arr[], int n) {
	if (n % 2 == 0)
		return (arr[n / 2] + arr[n / 2 - 1] / 2);
	else
		return arr[n / 2];

}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:/input_output/input.txt", "r", stdin);
	freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here

	int arr1[] = {1, 2, 3, 6};
	int arr2[] = {4, 6, 8, 10};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	if (n1 == n2)
		cout << "Median is " << getMedian(arr1, arr2, n1);
	else
		cout << "Doesn't work for arrays of unequal size";
	return 0;
}
