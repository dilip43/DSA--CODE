#include<bits/stdc++.h>
using namespace std;

int arrayRotateCheck(int *arr, int size) {
	int start = 0;
	int end = size - 1;
	int mid = start + (end - start) / 2;
	int last = arr[end];
	while (start <= end) {
		if (arr[mid] > last) {
			start = mid + 1;
		}
		else if (arr[mid] < last) {
			end = mid - 1;
		}
		else
			break;
		mid = start + (start - end) / 2;
	}
	return mid;
}

int main() {

	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}



	return 0;
}