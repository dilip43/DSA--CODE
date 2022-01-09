#include<bits/stdc++.h>
#include<stack>
using namespace std;

int [] stock_span(int price[]) {
	int n = price.length;
	int span[n];
	stack<int>st;
	st.push(0);
	span[0] = 1;
	for (int i = 1; i < n; i++) {
		while (!st.empty() && price[st.top()] <= price[i]) {
			st.pop();
		}
		if (st.empty()) {
			span[i] = i + 1;
		}
		else {
			span[i] = i - st.top();
		}
	}
	return span;
}

int main() {



	return 0;
}