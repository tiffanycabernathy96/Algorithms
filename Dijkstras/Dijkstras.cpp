// Tiffany Abernathy - Implementation of Dijkstra's

#include "Dijkstras.h"
#include <iostream>
using namespace std;

const int NUMVERTSMATRIX = 9;
const int NUMVERTSLIST = 7;

void dijkstras(AdjacencyListGraph* iGraph, int* iDistance, int iStart) {

}

void dijkstras(AdjacencyMatrixGraph* iGraph, int* iDistance, int iStart) {

}

int main()
{
    AdjacencyMatrixGraph* matrixGraph = new AdjacencyMatrixGraph(NUMVERTSMATRIX);
    matrixGraph->addEdge(AMGraph::Edge(0, 1, 4));
    matrixGraph->addEdge(AMGraph::Edge(0, 7, 8));

    matrixGraph->addEdge(AMGraph::Edge(1, 0, 4));
    matrixGraph->addEdge(AMGraph::Edge(1, 2, 8));
    matrixGraph->addEdge(AMGraph::Edge(1, 7, 11));

    matrixGraph->addEdge(AMGraph::Edge(2, 1, 8));
    matrixGraph->addEdge(AMGraph::Edge(2, 3, 7));
    matrixGraph->addEdge(AMGraph::Edge(2, 5, 4));
    matrixGraph->addEdge(AMGraph::Edge(2, 8, 2));

    matrixGraph->addEdge(AMGraph::Edge(3, 2, 7));
    matrixGraph->addEdge(AMGraph::Edge(3, 4, 9));
    matrixGraph->addEdge(AMGraph::Edge(3, 5, 14));

    matrixGraph->addEdge(AMGraph::Edge(4, 3, 9));
    matrixGraph->addEdge(AMGraph::Edge(4, 5, 10));

    matrixGraph->addEdge(AMGraph::Edge(5, 2, 4));
    matrixGraph->addEdge(AMGraph::Edge(5, 3, 14));
    matrixGraph->addEdge(AMGraph::Edge(5, 4, 10));
    matrixGraph->addEdge(AMGraph::Edge(5, 6, 2));

    matrixGraph->addEdge(AMGraph::Edge(6, 5, 2));
    matrixGraph->addEdge(AMGraph::Edge(6, 7, 1));
    matrixGraph->addEdge(AMGraph::Edge(6, 8, 6));

    matrixGraph->addEdge(AMGraph::Edge(7, 0, 8));
    matrixGraph->addEdge(AMGraph::Edge(7, 1, 11));
    matrixGraph->addEdge(AMGraph::Edge(7, 6, 1));
    matrixGraph->addEdge(AMGraph::Edge(7, 8, 7));
    
    matrixGraph->addEdge(AMGraph::Edge(8, 2, 2));
    matrixGraph->addEdge(AMGraph::Edge(8, 6, 6));
    matrixGraph->addEdge(AMGraph::Edge(8, 7, 7));

    matrixGraph->printMatrix();
    /*
    Output:
        0 to 0 - Cost: 0
        0 to 1 - Cost: 4
        0 to 2 - Cost: 12
        0 to 3 - Cost: 19
        0 to 4 - Cost: 21
        0 to 5 - Cost: 11
        0 to 6 - Cost: 9
        0 to 7 - Cost: 8
        0 to 8 - Cost: 14
    */

    cout << endl;

    AdjacencyListGraph* adjListGraph = new AdjacencyListGraph(NUMVERTSLIST);
    adjListGraph->addEdge(0, 1, 3);
    adjListGraph->addEdge(0, 2, 6);
    adjListGraph->addEdge(1, 0, 3);
    adjListGraph->addEdge(1, 2, 2);
    adjListGraph->addEdge(1, 3, 1);
    adjListGraph->addEdge(2, 1, 6);
    adjListGraph->addEdge(2, 1, 2);
    adjListGraph->addEdge(2, 3, 1);
    adjListGraph->addEdge(2, 4, 4);

    adjListGraph->addEdge(2, 5, 2);
    adjListGraph->addEdge(3, 1, 1);
    adjListGraph->addEdge(3, 2, 1);
    adjListGraph->addEdge(3, 4, 2);
    adjListGraph->addEdge(3, 6, 4);
    adjListGraph->addEdge(4, 2, 4);
    adjListGraph->addEdge(4, 3, 2);
    adjListGraph->addEdge(4, 5, 2);
    adjListGraph->addEdge(4, 6, 1);
    adjListGraph->addEdge(5, 2, 2);
    adjListGraph->addEdge(5, 4, 2);
    adjListGraph->addEdge(5, 6, 1);
    adjListGraph->addEdge(6, 3, 4);
    adjListGraph->addEdge(6, 4, 1);
    adjListGraph->addEdge(6, 5, 1);

    adjListGraph->printPretty();

    /*
    Output:
        0 to 0 - Cost: 0
        0 to 1 - Cost: 3 
        0 to 2 - Cost: 5 
        0 to 3 - Cost: 4 
        0 to 4 - Cost: 6
        0 to 5 - Cost: 7 
        0 to 6 - Cost: 7
    */
}

