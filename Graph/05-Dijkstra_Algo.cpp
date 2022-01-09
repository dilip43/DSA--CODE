#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int* distance, bool* visited, int n) {
	int minVertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && (minVertex == -1 || distance[i] < distance [minVertex])) {
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int** Edges, int n) {
	int* distance = new int[n];
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = INT_MAX;
		visited[i] = false;
	}

	distance[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		int minVertex = findMinVertex(distance, visited);
		visited[minVertex] = true;
		//explore neighbour
		for (int j = 0; j < n; j++)
		{
			if (Edges[minVertex][j] != 0 && !visited[j] && distance[minVertex] != INT_MAX) {
				int dist = distance[minVertex] + Edges[minVertex][j];
				if (dist < distance[j]) {
					distance[j] = dist;
				}
			}
		}
	}
	//print
	for (int i = 0; i < n; i++)
		cout << i << " " << distance[i];

	delete[] vistied;
	delete[] distance;
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
	dijkstra(Edges, n);

	for (int i = 0; i < n; i++) {
		delete [] Edges[i];
	}

	delete [] Edges;
}