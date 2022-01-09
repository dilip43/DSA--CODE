//cycle detection in undirected graph using bfs
#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, int v, vector<int>adj[], vector<int>& visited) {
	queue<pair<int, int>>q;
	visited[s] = true;
	q.push({s, -1});

	while (!q.empty()) {
		int node = q.front().first;
		int par = q.front().second;
		q.pop();

		for (auto it : adj[node]) {
			if (!visited[it]) {
				visited[it] = true;
				q.push({it, node});
			}
			else if (par != it)
				return true;
		}
	}
	return false;
}


bool iscycle(int v, vector<int>adj[]) {
	vector<int>vis(v + 1, 0);
	for (int i = 1; i <= v; i++) {
		if (!vis[i]) {
			if (checkForCycle(i, v, adj, vis))
				return true;
		}
	}
	return false;
}

int main() {
	int v, e; cin >> v >> e;
	vector<int>adj[v];
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool ans = iscycle(v, adj);
	if (ans)
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}