#include<bits/stdc++.h>
#include<stack>
using namespace std;

void reverseStack(stack<int>s1, stack<int>s2) {
	if (s1.size() <= 1) {
		return;
	}
	int x = s1.pop();
	reverseStack(s1, s2);

	while (!s1.empty()) {
		int a = s1.pop();
		s2.push(a);
	}

	s1.push(x);
	while (!s2.empty()) {
		int b = s2.pop();
		s1.push(b);
	}
}

int main() {

	stack<int>s;
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	stack<int>s2;
	reverseStack(s, s2);
	while (!s.empty()) {
		cout << s.pop();
	}

	return 0;
}