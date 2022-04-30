#pragma once
#include "AdjacencyMatrixGraph.h"
#include "AdjacencyListGraph.h"
#include <list>
using namespace std;

void static printDistance(int* iDistance, int iSize, int iStart);
int static minimum(list<int> iUnvisited, int* iDistance);
void static dijkstras(AdjacencyListGraph* iGraph, int* iDistance, int iStart);
void static dijkstras(AdjacencyMatrixGraph* iGraph, int* iDistance, int iStart);