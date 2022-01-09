#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int si, int ei) {
	int pivot = a[si];
	int countSmaller = 0;
	for (int i = si + 1; i <= ei; i++) {
		if ( a[i] <= pivot)
			countSmaller++;
	}
	int pivotIndex = countSmaller + si;
	a[si] = a[pivotIndex];
	a[pivotIndex] = pivot;

	int i = si;
	int j = ei;
	while (i < pivotIndex && j > pivotIndex) {
		if (a[i] <= pivot) {
			i++;
		}
		else if (a[j] > pivot) {
			j--;
		}
		else {
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	return pivotIndex;
}

void quick_sort(int a[], int si, int ei) {
	if (si >= ei)
		return;

	int p = partition(a, si, ei);
	quick_sort(a, si, p - 1);
	quick_sort(a, p + 1, ei);
}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:/input_output/input.txt", "r", stdin);
	freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here

	int a[] = {5, 8, 7, 2, 3, 1, 9};
	quick_sort(a, 0, 6);
	for (int i = 0; i < 7; i++) {
		cout << a[i] << " ";
	}

	return 0;
}
