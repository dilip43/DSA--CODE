#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool ismatch(char a, char b) {
	if (a == '}' && b == '{')
		return true;
	else if (a == ']' && b == '[')
		return true;
	else if (a == ')' && b == '(')
		return true;
	else
		return false;
}

bool isValid(string s) {
	stack<char>stack;
	for (int i = 0; i < s.length(); i++) {
		char a = s[i];
		if (a == '{' || a == '[' || a == '(')
			stack.push(a);
	
	if (a == '}' || a == ']' || a == ')') {
		if (stack.empty())
			return false;
		else if (!ismatch(a, stack.top())) {
			return false;
		}
		else {
			stack.pop();
		}
	}
}
	if (stack.empty())
		return true;
	else
		return false;
}

int main() {



	return 0;
}