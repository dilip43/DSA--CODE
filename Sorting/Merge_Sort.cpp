#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int si, int ei) {
	int size = ei - si + 1;
	int mid = (si + ei) / 2;
	int* out = new int[size];
	int i = si, j = mid + 1, k = 0;
	while (i <= mid && j <= ei) {
		if (a[i] < a[j])
			out[k++] = a[i++];
		else
			out[k++] = a[j++];
	}
	while (i <= mid) {
		out[k++] = a[i++];
	}
	while (j <= ei) {
		out[k++] = a[j++];
	}
	int m = 0;
	for (int i = si; i <= ei; i++) {
		a[i] = out[m++];
	}
	delete [] out;
}

void merge_sort(int a[], int si, int ei) {
	if (si >= ei) {
		return;
	}
	int mid = si + (ei - si) / 2;
	merge_sort(a, si, mid);
	merge_sort(a, mid + 1, ei);
	merge(a, si, ei);
}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:/input_output/input.txt", "r", stdin);
	freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here

	int a[] = {6, 5, 4, 3, 2, 1};
	merge_sort(a, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
