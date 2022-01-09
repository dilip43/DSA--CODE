#include<bits/stdc++.h>

class PriorityQueue {
	vector<int>pq;

public:
	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}

	int getSize() {
		return pq.size();
	}

	int getMin() {
		if (isEmpty())
			return 0;

		return pq[0];
	}

	void insert(int elment) {
		pq.push_back(elment);

		int childIndex = pq.size() - 1;


		while (childIndex > 0 ) {
			int parentIndex = (childIndex - 1) / 2;
			if (pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
	}

	int removeMin() {
		if (isEmpty())
			return 0;

		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		//down-heapify
		int parentIndex = 0;
		int leftchildIndex = 2 * parentIndex + 1;
		int rightchildIndex = 2 * parentIndex + 2;
		while (leftchildIndex < pq.size()) {
			int minIndex = parentIndex;
			if (pq[minIndex] > pq[leftchildIndex]) {
				minIndex = leftchildIndex;
			}
			if (rightchildIndex < pq.size() && pq[minIndex] > pq[rightchildIndex]) {
				minIndex = rightchildIndex;
			}
			if (minIndex == parentIndex) {
				break;
			}

			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			leftchildIndex = 2 * parentIndex + 1;
			rightchildIndex = 2 * parentIndex + 2;
		}
		return ans;
	}



};