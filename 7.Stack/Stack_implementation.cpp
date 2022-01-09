#include<bits/stdc++.h>
using namespace std;

class stack {
private:
	int data[];
	int top;
public:
	stack() {
		data = new int[10];
		top = -1;
	}
	stack(int capacity) {
		data = new int[capacity];
		top = -1;
	}
	bool isempty() {
		return (top == -1);
	}
	int size() {
		return top + 1;
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
