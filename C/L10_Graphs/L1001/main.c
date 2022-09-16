#include <stdio.h>
#include "AdjMatrix.h"
int main()
{
    createMatrix(7);
    defaults(7);
    addEdge(1, 2);
    addEdge(2, 1);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(3, 2);
    addEdge(3, 4);
    addEdge(4, 2);
    addEdge(4, 3);
    addEdge(4, 5);
    addEdge(4, 7);
    addEdge(5, 4);
    addEdge(5, 6);
    addEdge(6, 5);
    addEdge(6, 7);
    addEdge(7, 4);
    addEdge(7, 6);
    printfArr(7);
    printf("\nDepth : \n");
    depthFirstTraversal();
    printf("\nbreadth First : \n");
    breadthFirstTraversal();
    return 0;
}