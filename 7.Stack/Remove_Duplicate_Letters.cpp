// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make
//  sure your result is the smallest in lexicographical order among all possible results.


#include<bits/stdc++.h>
#include<stack>
#include<climits>
using namespace std;

string removeDuplicateLetters(string s)
{
	int lastIndex[26] = {0};
	bool presentInStack[26] = {0};
	for (int i = 0; i < s.length(); i++) {
		lastIndex[s[i] - 'a'] = i;
	}
	stack<char>stack;
	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];
		if (!presentInStack[ch - 'a']) {
			while (!stack.empty() && ch < stack.top() && lastIndex[stack.top() - 'a'] > i) {
				presentInStack[stack.top() - 'a'] = false;
				stack.pop();
			}

			stack.push(ch);
			presentInStack[ch - 'a'] = true;
		}
	}
	int k = stack.size();
	char* ans = new char[k + 1];
	ans[k--] = '\0';
	while (!stack.empty()) {
		ans[k] = stack.top();
		stack.pop();
		k--;
	}
	string final(ans);
	return final;
}

int main() {

	string str;
	cin >> str;
	cout << removeDuplicateLetters(str);

	return 0;
}