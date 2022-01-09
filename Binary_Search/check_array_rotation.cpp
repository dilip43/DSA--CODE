#include<bits/stdc++.h>
using namespace std;

int find_key(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else if (a[s] <= a[mid]) {
			if (key >= a[s] && key <= a[mid]) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		else if (key >= a[mid] && key <= a[e]) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
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

	int arr[] = {2, 9, 2, 2, 2};
	int n = sizeof(arr) / sizeof(int);
	int target = 9;

	cout << find_key(arr, n, target);


	return 0;
}


