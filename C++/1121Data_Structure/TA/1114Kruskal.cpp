#include <algorithm>
#include <iomanip> // for setw()
#include <iostream>
#include <list>
#include <vector>

struct Edge {
	int from, to, weight;
	Edge(){};
	Edge(int u, int v, int w)
		: from(u)
		, to(v)
		, weight(w){};
};

class GraphMST {
    private:
	int numVertex;
	std::vector<std::vector<int> > adjMatrix;

    public:
	GraphMST()
		: numVertex(0){};

	GraphMST(int n)
		: numVertex(n)
	{
		adjMatrix.resize(numVertex);
		for (int i = 0; i < numVertex; i++)
			adjMatrix[i].resize(numVertex);
	}

	void AddEdge(int from, int to, int weight);

	void KruskalMST();
	void GetSortedEdge(std::vector<struct Edge> &vec);
	friend int FindSetCollapsing(int *subset, int i);
	friend void UnionSet(int *subset, int x, int y);
};

// Use recursion for collapsing
int FindSetCollapsing(int *subset, int i)
{
	// Find the root of the subset to which element i belongs
	int root;
	for (root = i; subset[root] >= 0; root = subset[root])
		;
	// Path compression: Update the parent pointers to point directly to the
	// root
	while (i != root) {
		int parent = subset[i];
		subset[i] = root;
		i = parent;
	}

	return root;
}

void UnionSet(int *subset, int x, int y)
{
	int xroot = FindSetCollapsing(subset, x),
	    yroot = FindSetCollapsing(subset, y);

	// Compare by rank, more negative values indicate more elements in the set,
	// so smaller values represent more elements
	// xroot, yroot's subset[] is always negative

	// If x has more elements or equal, set x as the root
	if (subset[xroot] <= subset[yroot]) {
		subset[xroot] += subset[yroot];
		subset[yroot] = xroot;

	}
	// if (subset[xroot] > subset[yroot]), indicates y has more elements
	else {
		subset[yroot] += subset[xroot];
		subset[xroot] = yroot;
	}
}

bool WeightComp(struct Edge e1, struct Edge e2)
{
	return (e1.weight < e2.weight);
}

void GraphMST::GetSortedEdge(std::vector<struct Edge> &edgeArr)
{
	for (int i = 0; i < numVertex - 1; i++) {
		for (int j = i + 1; j < numVertex; j++)
			if (adjMatrix[i][j] != 0)
				edgeArr.push_back(Edge(i, j, adjMatrix[i][j]));
	}
	std::sort(edgeArr.begin(), edgeArr.end(), WeightComp);
}

void GraphMST::KruskalMST()
{
	struct Edge *edgeSetMST = new struct Edge[numVertex - 1];

	int edgeSetCount = 0;

	// //Initialize subset
	int subset[numVertex];
	for (int i = 0; i < numVertex; i++)
		subset[i] = -1;

	std::vector<struct Edge> increaseWeight;
	GetSortedEdge(increaseWeight);

	// Check if adding this edge will create a cycle,
	// if not, add this edge to edgeSetMST and handle the union of disjoint sets
	for (int i = 0; i < increaseWeight.size(); i++) {
		// your code goes here
		int from = FindSetCollapsing(subset, increaseWeight[i].from);
		int to = FindSetCollapsing(subset, increaseWeight[i].to);

		if (from != to) {
			edgeSetMST[edgeSetCount] = increaseWeight[i];
			edgeSetCount++;
			UnionSet(subset, from, to);
		}
	}
	// The following is just printing the predecessor between vertices
	std::cout << std::setw(3) << "v1"
		  << " - " << std::setw(3) << "v2"
		  << " : weight\n";
	for (int i = 0; i < numVertex - 1; i++)
		std::cout << std::setw(3) << edgeSetMST[i].from << " - "
			  << std::setw(3) << edgeSetMST[i].to << " : "
			  << std::setw(4) << edgeSetMST[i].weight << "\n";
}

void GraphMST::AddEdge(int from, int to, int weight)
{
	adjMatrix[from][to] = weight;
}

int main()
{
	GraphMST g6(7);
	g6.AddEdge(0, 1, 5);
	g6.AddEdge(0, 5, 3);
	g6.AddEdge(1, 0, 5);
	g6.AddEdge(1, 2, 10);
	g6.AddEdge(1, 4, 1);
	g6.AddEdge(1, 6, 4);
	g6.AddEdge(2, 1, 10);
	g6.AddEdge(2, 3, 5);
	g6.AddEdge(2, 6, 8);
	g6.AddEdge(3, 2, 5);
	g6.AddEdge(3, 4, 7);
	g6.AddEdge(3, 6, 9);
	g6.AddEdge(4, 1, 1);
	g6.AddEdge(4, 3, 7);
	g6.AddEdge(4, 5, 6);
	g6.AddEdge(4, 6, 2);
	g6.AddEdge(5, 0, 3);
	g6.AddEdge(5, 4, 6);
	g6.AddEdge(6, 1, 4);
	g6.AddEdge(6, 2, 8);
	g6.AddEdge(6, 3, 9);
	g6.AddEdge(6, 4, 2);

	std::cout << "MST found by Kruskal:\n";
	g6.KruskalMST();

	return 0;
}
