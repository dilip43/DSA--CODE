bool isMaxHeap(int arr[], int n) {
	while (n - 1 > 0) {
		int ci = n - 1;
		while (ci > 0) {
			int pi = (ci - 1) / 2;
			if (pi > 0 && arr[ci] > arr[pi]) {
				return false;
			}
			ci = pi;
		}
		n--;
	}
	return true;
}