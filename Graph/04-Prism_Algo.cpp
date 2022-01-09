#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int* weights, bool* visited, int n) {
	int minVertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) {
			minVertex = i;
		}
	}
	return minVertex;
}

void prism(int** Edges, int n) {
	bool* visited = new bool[n];
	int* weights = new int[n];
	int* parent = new int[n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
		weights[i] = INT_MAX;
	}

	parent[0] = -1;
	weights[0] = 0;

	for (int i = 0; i < n; i++) {
		//find min vertex
		int minVertex = findMinVertex(weights, visited, n);
		visited[minVertex] = true;
		//explore unvisited neighbour
		for (int j = 0; j < n; j++) {
			if (Edges[minVertex][j] != 0 && !visited[j]) {
				if (Edges[minVertex][j] < weights[j]) {
					weights[j] = Edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	//print out the MST
	for (int i = 1; i < v; i++) {
		if (parent[i] < i)
			cout << parent[i] << " " << i << " " << weights[i] << endl;
		else
			cout << i << " " << parent[i] << " " << weights[i] << endl;
	}

}


int main() {
	int n, e; cin >> n >> e;
	int** Edges = new int*[n];
	for (int i = 0; i < n; i++) {
		Edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			Edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		adj[f][s] = weight;
		adj[s][f] = weight;
	}
	count << endl;
	prism(Edges, n);
}