#include<bits/stdc++.h>
#include<queue>
#include<climits>
using namespace std;
class Queue {
	int *arr;
	int f, ms, cs, r;
public:
	Queue(int n) {
		arr = new int[n];
		cs = 0;
		ms = n;
		f = 0;
		r = n - 1;
	}
	void push(int data) {
		if (cs == ms)
			return ;
		r = (r + 1) % ms;
		arr[r] = data; cs++;
	}
	void pop() {
		if (cs == 0)return ;
		f = (f + 1) % ms;
		cs--;
	}
	bool empty() {
		return cs == 0;
	}
	bool full() {
		return cs == ms;
	}
	int front() {
		return arr[f];
	}
	int size() {
		return cs;
	}
};

void CircularQueue() {
	int k;
	cin >> k;
	Queue q(k);
	int n;
	cin >> n;
	int sum = 0;
	while (n != -1) {
		sum += n;
		if (q.full()) {
			sum -= q.front();
			q.pop();
		}
		q.push(n);
		cout << (double)(sum) / q.size() << "'";
		cin >> n;
	}
}

void average() {
	int k;	cin >> k;
	queue<int>q;
	int n; cin >> n;
	int sum = 0;
	while (n != -1) {
		sum += n;
		q.push(n);
		if (q.size() > k) {
			sum -= q.front();
			q.pop();
		}

		cout << (double)(sum) / q.size() << "'";
		cin >> n;
	}
}

int main() {

	CircularQueue();

	return 0;
}