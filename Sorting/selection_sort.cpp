#include<bits/stdc++.h>
using namespace std;

int getMaxindex(int arr[], int start, int end) {
	int max = start;
	for (int i = start; i <= end; i++) {
		if (arr[max] < arr[i])
			max = i;
	}
	return max;
}

void selction(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int last = size - i - 1;
		int maxIndex = getMaxindex(arr, 0, last);
		swap(arr[maxIndex], arr[last]);
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
	int arr[] = {4, 5, 1, 2, 3};
	selction(arr, 5);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	return 0;
}
