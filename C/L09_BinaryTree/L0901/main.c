#include "binaryTree.h"
int main() {
  struct  node* root = newNode(10);
  insert_node(root, 20);
  insert_node(root, 30);
  insert_node(root, 40);
  insert_node(root, 25);
  insert_node(root, 35);
  insert_node(root, 39);
  insert_node(root, 45); 
  insert_node(root, 16); 
  insert_node(root, 28); 
  insert_node(root, 9); 
  insert_node(root, 32); 
  printf("\n----------Before delete 20, 35---------\n\n");
  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");
  printf("\nBreath first traversal: ");
  breathFirst(root);
  printf("\n");        
  printf("\n----------After delete 20, 35----------\n");  
  delete_copying(root, 20);
  delete_copying(root, 35);     
  printf("\nPostorder traversal: ");
  postorder(root);
  printf("\n");
  printf("\nInorder traversal: ");
  inorder(root); 
  printf("\n"); 
  return 0;    
}
