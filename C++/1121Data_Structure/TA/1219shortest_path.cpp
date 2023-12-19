#include <climits>
#include <iomanip>
#include <iostream>

#define v 5 // Number of vertices (vertexNum)
#define maxV INT_MAX
using namespace std;

// Function to find the vertex with the minimum distance value,
// from the set of vertices not yet included in the shortest path tree
int miniDist(int dist[], bool isVisit[]) {
	int minIndex = -1; // Indicates that a valid unvisited node is not found
	int minValue = maxV;
	for (int i = 0; i < v; i++) {
		if (!isVisit[i] && dist[i] < minValue) {
			minValue = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
	// your code goes here
}

// Function to initialize distance array and isVisit array
void init(int dist[], bool isVisit[], int parent[]) {
	for (int i = 0; i < v; i++) {
		dist[i] = INT_MAX;
		isVisit[i] = false;
		parent[i] = i;
	}
}

char mapIndexToLetter(int i) { return 'A' + i; }

// Function to find and print the shortest path from source to a given vertex
void findParent(int parent[], int n, int src) {
	while (parent[n] != src) {
		if (parent[n] == n) {
			cout << "cannot reach!" << endl;
			return;
		}
		n = parent[n];
		cout << "->" << mapIndexToLetter(n);
	}
	cout << "->" << mapIndexToLetter(src);
	return;
}

// Dijkstra's algorithm to find the shortest paths from a source vertex to all
// other vertices
void DijkstraAlgo(int graph[v][v], int src) {
	int dist[v], parent[v];
	bool isVisit[v];
	init(dist, isVisit, parent);

	// Set the distance of the source vertex to 0
	dist[src] = 0;

	while (true) {
		// Get the current node with the minimum distance value
		int vertex = miniDist(dist, isVisit);
		if (vertex == -1)
			break; // All nodes have been visited, exit the loop

		isVisit[vertex] = true;

		// Relaxation step
		for (int i = 0; i < v; i++) {
			if (!isVisit[i] && graph[vertex][i] != INT_MAX &&
				dist[i] > dist[vertex] + graph[vertex][i]) {
				dist[i] = dist[vertex] + graph[vertex][i];
				parent[i] = vertex;
			}
		}
	}

	// Print the final distance from the source vertex to each vertex
	cout << "vertex\tdist from src" << endl;
	for (int i = 0; i < v; i++) {
		cout << mapIndexToLetter(i) << setw(8) << setfill(' ') << dist[i]
			 << setw(15) << setfill(' ');
		findParent(parent, i, src);
		cout << endl;
	}
}

int main() {
	int graph[v][v] = {{maxV, 10, 3, maxV, maxV},
					   {maxV, maxV, 1, 2, maxV},
					   {maxV, 4, maxV, 8, 2},
					   {maxV, maxV, maxV, maxV, 7},
					   {maxV, maxV, maxV, 9, maxV}};
	DijkstraAlgo(graph, 0);
	return 0;
}
