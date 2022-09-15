#include "BinarySearchTree.h"
int main()
{
    struct binary_search_tree *root = newNode(30);
    insert_node(root, 40);
    insert_node(root, 20);
    insert_node(root, 25);
    insert_node(root, 46);
    insert_node(root, 32);
    insert_node(root, 31);
    insert_node(root, 35);
    insert_node(root, 22);
    insert_node(root, 26);
    insert_node(root, 10);
    insert_node(root, 8);
    insert_node(root, 12);
    insert_node(root, 11);
    printf("PreOrder #: ");
    preOrder(root);
    printf("\n\n");
    printf("InOrder #: ");
    inOrder(root);
    printf("\n\n");
    printf("PostOrder #: ");
    postOrder(root);
    printf("\n\n");
    printf("Min #: %d\n", findMin(root));
    printf("\n\n");
    printf("Max #: %d", findMax(root));
    printf("\n\n");
    printf("****Delete 20*****\n");
    delete_copying(root, 20);
    printf("BreathFirst #: ");
    breathFirst(root);
    printf("\n\n");
    printf("Sum := %d\n", findSum(root));
    printf("\n\n");
    printf("Search 47 #: %s\n", search_node(root, 47) ? "true" : "false");
    return 0;
}
