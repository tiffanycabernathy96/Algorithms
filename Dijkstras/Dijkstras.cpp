// Tiffany Abernathy - Implementation of Dijkstra's
// Implementation for Both Adjacencmy Matrix Graph and Adjacency List Graph
#include "Dijkstras.h"
#include <iostream>
using namespace std;

void printDistance(int* iDistance, int iSize, int iStart) {
    cout << endl << "Shortest Path To Each Node From: " << iStart << endl;
    for (int i = 0; i < iSize; i++) {
        //No Connection from Start to i
        if (iDistance[i] == INT_MAX)
            cout << iStart << " to " << i << " - Not Connected" << endl;
        //Connection Exists from Start to i
        else
            cout << iStart << " to " << i << " - Cost: " << iDistance[i] << endl;
    }
        
}

int minimum(list<int> iUnvisited, int* iDistance) {
    //Find the node not yet visited that has the smallest distance
    int min = INT_MAX;
    int index = -1;
    for (int i : iUnvisited) {
        //Make sure the min always gets set
        if (index == -1) {
            min = iDistance[i];
            index = i;
        }
        //Replace the min if smaller is found
        else if (iDistance[i] < min) {
            min = iDistance[i];
            index = i;
        }
    }
    return index;
}

void dijkstras(AdjacencyListGraph* iGraph, int* iDistance, int iStart) {
    //Set the distance for all of the nodes to max
    for (int i = 0; i < iGraph->numVertices; i++) {
        //Set to Infinity
        iDistance[i] = INT_MAX;
    }
    //The distance to the starting node is 0. 
    iDistance[iStart] = 0;

    //List to Hold Unvisited Nodes
    list<int> unvisited;
    for (int i = 0; i < iGraph->numVertices; i++)
        unvisited.push_back(i);

    //While there are still unvisited nodes
    while (!unvisited.empty()) {
        //Find the node with the smallest distance from start thus far
        int minElement = minimum(unvisited, iDistance);
        //Mark it as visited
        unvisited.remove(minElement);
        //Go through all of the connections from that node
        ALGraph::Edge* temp = iGraph->adjList[minElement]->next;
        //Update shortest paths where needed
        while (temp) {
            if ((iDistance[minElement] + temp->weight) < iDistance[temp->end->name] && (iDistance[minElement] != INT_MAX))
                iDistance[temp->end->name] = (iDistance[minElement] + temp->weight);
            temp = temp->next;
        }
    }
    //Print the Result
    printDistance(iDistance, iGraph->numVertices, iStart);
}

void dijkstras(AdjacencyMatrixGraph* iGraph, int* iDistance, int iStart) {
    //Same as above except for Adjacency Matrix Graph
    for (int i = 0; i < iGraph->numVertices; i++) {
        iDistance[i] = INT_MAX;
    }
    iDistance[iStart] = 0;

    list<int> unvisited;
    for (int i = 0; i < iGraph->numVertices; i++)
        unvisited.push_back(i);

    while (!unvisited.empty()) {
        int minElement = minimum(unvisited, iDistance);
        unvisited.remove(minElement);
        for (int j = 0; j < iGraph->numVertices; j++) {
            if (iGraph->adjMatrix[minElement][j] != -1 && (iDistance[minElement] + iGraph->adjMatrix[minElement][j]) < iDistance[j] && (iDistance[minElement] != INT_MAX))
                iDistance[j] = (iDistance[minElement] + iGraph->adjMatrix[minElement][j]);
        }
    }
    printDistance(iDistance, iGraph->numVertices, iStart);
}

int main()
{
    int start = 0;
    int distanceM[9];
    AdjacencyMatrixGraph* matrixGraph = new AdjacencyMatrixGraph(9);
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
    dijkstras(matrixGraph, distanceM, start);
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

    int distanceL[7];
    AdjacencyListGraph* adjListGraph = new AdjacencyListGraph(7);
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

    dijkstras(adjListGraph, distanceL, start);

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

    cout << endl;

    //The Next Two are the Same Graph Represented with Adjacency Matrix Graph and Adjacency List Graph So Their Outputs should be Equal

    int distance[8];
    AdjacencyMatrixGraph* matrixGraph2 = new AdjacencyMatrixGraph(8);
    matrixGraph2->addEdge(AMGraph::Edge(0, 3, 9));
    matrixGraph2->addEdge(AMGraph::Edge(0, 4, 4));

    matrixGraph2->addEdge(AMGraph::Edge(1, 5, 5));

    matrixGraph2->addEdge(AMGraph::Edge(2, 6, 7));

    matrixGraph2->addEdge(AMGraph::Edge(3, 1, 5));
    matrixGraph2->addEdge(AMGraph::Edge(3, 7, 9));

    matrixGraph2->addEdge(AMGraph::Edge(4, 2, 5));
    matrixGraph2->addEdge(AMGraph::Edge(4, 7, 3));

    matrixGraph2->addEdge(AMGraph::Edge(5, 3, 5));
    matrixGraph2->addEdge(AMGraph::Edge(5, 7, 1));

    matrixGraph2->addEdge(AMGraph::Edge(6, 7, 9));

    matrixGraph2->addEdge(AMGraph::Edge(7, 5, 5));
    matrixGraph2->addEdge(AMGraph::Edge(7, 6, 6));

    matrixGraph2->printMatrix();
    dijkstras(matrixGraph2, distance, start);
    dijkstras(matrixGraph2, distance, 5);

    cout << endl;

    AdjacencyListGraph* adjListGraph2 = new AdjacencyListGraph(8);
    adjListGraph2->addEdge(0, 3, 9);
    adjListGraph2->addEdge(0, 4, 4);

    adjListGraph2->addEdge(1, 5, 5);

    adjListGraph2->addEdge(2, 6, 7);

    adjListGraph2->addEdge(3, 1, 5);
    adjListGraph2->addEdge(3, 7, 9);

    adjListGraph2->addEdge(4, 2, 5);
    adjListGraph2->addEdge(4, 7, 3);

    adjListGraph2->addEdge(5, 3, 5);
    adjListGraph2->addEdge(5, 7, 1);

    adjListGraph2->addEdge(6, 7, 9);

    adjListGraph2->addEdge(7, 5, 5);
    adjListGraph2->addEdge(7, 6, 6);

    adjListGraph2->printPretty();
    dijkstras(adjListGraph2, distance, start);
    dijkstras(adjListGraph2, distance, 5);

    /*
    Output:
        0 to 0 - Cost: 0
        0 to 1 - Cost: 14 
        0 to 2 - Cost: 9
        0 to 3 - Cost: 9
        0 to 4 - Cost: 4
        0 to 5 - Cost: 12
        0 to 6 - Cost: 13
        0 to 7 - Cost: 7
    */
    /*
    Output:
        0 to 0 - Cost: MAX
        0 to 1 - Cost: 10
        0 to 2 - Cost: MAX
        0 to 3 - Cost: 5
        0 to 4 - Cost: MAX
        0 to 5 - Cost: 0
        0 to 6 - Cost: 7
        0 to 7 - Cost: 1
    */

}

