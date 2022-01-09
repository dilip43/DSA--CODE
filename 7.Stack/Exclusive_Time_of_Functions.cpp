#include<bits/stdc++.h>
using namespace std;

void convert(string str, int &id, string &operation, int &time) {
	int j = 0;
	id = time = 0;
	while (str[j] != ':') {
		id = id * 10 + str[j] - '0';
		j++;
	} j++;
	while (str[j] != ':') {
		operation.push_back(str[j]);
		j++;
	} j++;
	while (j < str.length()) {
		time = time * 10 + str[j] - '0';
		j++;
	}
	if (operation == "end")time++;
}

vector<int> exclusiveTime(int n, vector<string>& logs) {
	vector<int>duration(n, 0);
	stack<int>st;
	int prev_op_time;
	for (int i = 0; i < logs.size(); i++) {
		int id, time; string operation;
		convert(logs[i], id, operation, time);
		if (!st.empty()) {
			int fn_id = st.top();
			duration[fn_id] += (time - prev_op_time);
		}
		prev_op_time = time;
		if (operation == "start") {
			st.push(id);
		}
		else st.pop();
	}
	return duration;

}

int main() {

//...............ignore this part
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
//...............start the code from here



	return 0;
}
