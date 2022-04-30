#pragma once
#include "AMGraph.h"
using namespace AMGraph;

class AdjacencyMatrixGraph {
	
private:
	void bfsSearch(int iStart, bool* iVisited);
	void dfsR(int iStart, bool* iVisited);
public:
	int** adjMatrix;
	int numVertices;
	AdjacencyMatrixGraph(int iVertices);
	~AdjacencyMatrixGraph();

	void addEdge(AMGraph::Edge iEdge);
	void deleteEdge(AMGraph::Edge iEdge);

	void printMatrix();
	void print();

	void bfs(int iStart = -1);
	void dfs(int iStart = -1);
};