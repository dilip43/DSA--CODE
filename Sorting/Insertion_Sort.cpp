#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
			else {
				break;
			}
		}
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

	int arr[] = {5, 3, 4, 1, 2};
	insertionSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
