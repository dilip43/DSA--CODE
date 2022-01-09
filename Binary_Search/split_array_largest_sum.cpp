#include<bits/stdc++.h>
using namespace std;

int splitArray(int nums[], int m, int size) {
	int start = 0;
	int end = 0;
	for (int i = 0; i < size; i++) {
		start = max(start, nums[i]);
		end += nums[i];
	}
	//binary search
	while (start < end) {
		int mid = start + (end - start) / 2;
		//calculate in how many piece you can divide in this max sum
		int sum = 0;
		int pieces = 1;
		for (int num : nums) {
			if (sum + num > mid) {
				//you cannot add this in this subarray,make new one
				//say you add this num in new subarray,then sum=num
				sum = num;
				pieces++;
			} else {
				sum += num;
			}
		}
		if (pieces > m) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	return end; //here start==end
}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:/input_output/input.txt", "r", stdin);
	freopen("F:/input_output/output.txt", "w", stdout);
#endif
//...............start the code from here



	return 0;
}
