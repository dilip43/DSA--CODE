#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, e;
	cin >> n >> e;

	//declare the adjacent matrix
	int adj[n + 1][n + 1];

	//take edges as input
	for (int i = 0; i < e; i++) {
		int u, v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}



	return 0;
}
