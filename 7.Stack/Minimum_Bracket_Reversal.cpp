#include<bits/stdc++.h>
#include<stack>
using namespace std;

int CountBracketRemoval(string input) {
	int len = input.length();
	if (len % 2 != 0) {
		return -1;
	}
	stack<char>s;
	for (int i = 0; i < len; i++) {
		if (input[i] == '}' && !s.empty()) {
			if (s.top() == '{')
				s.pop();
			else
				s.push(input[i]);
		}
		else
			s.push(input[i]);
	}
	int red_len = s.size();
	int n = 0;
	while (!s.empty() && s.top() == '{') {
		s.pop();
		n++;
	}
	return (red_len / 2 + n % 2);
}

int main() {
	string str = "{{{}";
	cout << CountBracketRemoval(str);
	return 0;
}