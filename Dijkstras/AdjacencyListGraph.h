#pragma once
#include "ALGraph.h"
using namespace ALGraph;

class AdjacencyListGraph{
	
	
	void bfsSearch(int iStart, bool* iVisited);
	void dfsR(int iStart, bool* iVisited);
public:
	Node** adjList;
	int numVertices;

	AdjacencyListGraph(int iNumVertices);
	~AdjacencyListGraph();

	void addEdge(int iStart, int iEnd, int iWeight);
	void deleteEdge(int iStart, int iEnd, int iWeight);

	void print();
	void printPretty();

	void bfs(int iStart = -1);
	void dfs(int iStart = -1);
};