#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int>& vis, stack<int>&st, vector<int>adj[]) {
	vis[node] = 1;
	for (auto it : adj[node]) {
		if (!vis[it]) {
			findTopoSort(it, vis, st, adj);
		}
	}
	st.push(node);
}

vector<int> topoSort(int N, vector<int>adj[]) {
	stack<int>st;
	vector<int>vis(N, 0);
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			findTopoSort(i, vis, st, adj);
		}
	}
	vector<int>topo;
	while (!st.empty()) {
		topo.push_back(st.top());
		st.pop();
	}
	return topo;
}

int main() {
	int v, e; cin >> v >> e;
	vector<int>adj[v];
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int>ans = topoSort(v, adj);
	cout << check(v, res, adj) << endl;
	return 0;
}