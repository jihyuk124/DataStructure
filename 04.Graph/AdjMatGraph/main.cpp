#include<iostream>

using namespace std;

class Graph
{
public:
	Graph()
		: size(0)
		, vertices{ 0, }
		, adj{ {0,} }
	{
	}

	void insertVertex(char vertex)
	{
		vertices[size++] = vertex;
	}

	void insertEdge(int u, int v)
	{
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}

	void setEdge(int u, int v, int w)
	{
		adj[u][v] = w;
	}

	bool isFull() { return size >= MAX_VTXS; }
	bool isEmpty() { return size == 0; }

private:
	static const int MAX_VTXS = 256;
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
};

int main(void)
{
	Graph g;
}