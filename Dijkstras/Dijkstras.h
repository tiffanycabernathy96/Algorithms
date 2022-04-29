#pragma once
#include "AdjacencyMatrixGraph.h"
#include "AdjacencyListGraph.h"

void static dijkstras(AdjacencyListGraph* iGraph, int* iDistance, int iStart);
void static dijkstras(AdjacencyMatrixGraph* iGraph, int* iDistance, int iStart);