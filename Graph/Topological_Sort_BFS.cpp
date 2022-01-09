#include<bits/stdc++.h>
using namespace std;

vector<int> topo(int N, vector<int>adj[]) {
	queue<int>q;
	vector<int>indegree(N, 0);
	//making indegree array
	for (int i = 0; i < N; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}
	//pushing the value whose indegeree is 0
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int>topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0) {
				q.push(it);
			}
		}
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
	cout << isCyclic(v, adj) << endl;
	return 0;
}