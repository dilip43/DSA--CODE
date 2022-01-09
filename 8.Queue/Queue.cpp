#include<bits/stdc++.h>
using namespace std;

class queue {
public:
	int data[];
	int front, rear, size;

	queue() {
		data = new int[10];
		front = rear = -1;
		size = 0;
	}
	queue(int capacity) {
		data = new int[capacity];
		front = rear = -1;
		size = 0;
	}
	int size() {
		return size;
	}

	bool isempty() {
		return (size == 0);
	}

	int front() {
		if (size == 0)
			return INT_MIN;
		return data[front];
	}

	void enqueue(int element) {

	}

	int dequeue() {

	}
}

int main() {



	return 0;
}