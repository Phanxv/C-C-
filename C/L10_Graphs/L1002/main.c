#include "AdjacencyList.h"
int main()
{
    int V = 6;
    createGraph(V);
    addNode(0, "a");
    addNode(1, "b");
    addNode(2, "c");
    addNode(3, "d");
    addNode(4, "e");
    addNode(5, "f");
    printVertex();
    addEdge("a", "b");
    addEdge("a", "e");
    addEdge("b", "a");
    addEdge("e", "a");
    addEdge("e", "c");
    addEdge("e", "d");
    addEdge("c", "d");
    addEdge("c", "e");
    addEdge("d", "c");
    addEdge("d", "e");
    addEdge("d", "f");
    printGraph();
    depthFirstTraversal();
    breadthFirstTraversal();
    return 0;
}
