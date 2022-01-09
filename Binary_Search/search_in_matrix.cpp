#include<bits/stdc++.h>
using namespace std;

//search in the row provided between the cols provided
int[] binarySearch(int matrix[], int row, int cstart, int cend, int target) {
	while (cstart <= cend) {
		int mid = cstart + (cend - cstart) / 2;
		if (matrix[row][mid] == target) {
			return new int[] {row, mid};
		}
		if (matrix[row][mid] < target) {
			cstart = mid + 1;
		}
		else {
			cend = mid - 1;
		}
	}
	return new int[] { -1, -1};

}

int [] search(int [][]matrix, int target) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	if (rows == 1) {
		return binarySearch(matrix, 0, 0, cols, target);
	}
	//run the loop till 2 rows are remaining
	int rstart = 0;
	int rend = rows - 1;
	int cmid = cols / 2;
	while (rstart < (rend - 1)) {
		int mid = rstart + (rend - rstart) / 2;
		if (matrix[mid][cmid] == target) {
			return new int[] {mid, cmid};
		}
		if (matrix[mid][cmid] < target) {
			rstart = mid;
		}
		else {
			rend = mid;
		}
	}
	//now we have 2 rows
	//check whether the target is in the column of 2 rows
	if (matrix[rstart][cmid] == target) {
		return new int[] {rstart, cmid};
	}
	if (matrix[rstart + 1][cmid] == target) {
		return new int[] {rstart + 1, cmid};
	}

	//search in 1st half
	if (target <= matrix[rstart][cmid - 1]) {
		return binarySearch(matrix, rstart, 0, cmid - 1, target);
	}
	//search in 2nd half
	if (target <= matrix[rstart][cmid - 1] && target <= matrix[rstart][cols - 1]) {
		return binarySearch(matrix, rstart, cmid + 1, end, target);
	}
	//search in 3rd half
	if (target >= matrix[rstart + 1][cmid - 1]) {
		return binarySearch(matrix, rstart + 1, 0, cmid - 1, target);
	}
	//search in 4th half
	else {
		return binarySearch(matrix, rstart + 1, , cmid + 1, cols - 1, target);
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



	return 0;
}
