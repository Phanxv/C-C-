#include "linearQueue2.h"
struct binary_search_tree *newNode(int value)
{
   struct binary_search_tree *inst = (struct binary_search_tree *)malloc(sizeof(struct binary_search_tree));
   inst->value = value;
   inst->left = inst->right = NULL;
   return inst;
}
struct binary_search_tree *insert_node(struct binary_search_tree *root, int value)
{
   if (root == NULL)
   {
      return newNode(value);
   }
   if (value < root->value)
   {
      root->left = insert_node(root->left, value);
   }
   else if (value > root->value)
   {
      root->right = insert_node(root->right, value);
   }
   return root;
}
struct binary_search_tree *minNode(struct binary_search_tree *root)
{
   if (root == NULL)
   {
      return NULL;
   }
   else if (root->left == NULL)
   {
      return root;
   }
   return minNode(root->left);
}
struct binary_search_tree *maxNode(struct binary_search_tree *root)
{
   if (root != NULL)
   {
      while (root->right != NULL)
      {
         root = root->right;
      }
   }
   return root;
}
struct binary_search_tree *delete_copying(struct binary_search_tree *root, int value)
{
   if (root == NULL)
   {
      return root;
   }
   if (value < root->value)
   {
      root->left = delete_copying(root->left, value);
   }
   else if (value > root->value)
   {
      root->right = delete_copying(root->right, value);
   }
   else if (root->left != NULL && root->right != NULL)
   {
      root->value = minNode(root->right)->value;
      root->right = delete_copying(root->right, root->value);
   }
   else
   {
      root = (root->left != NULL) ? root->left : root->right;
   }
   return root;
}
bool search_node(struct binary_search_tree *root, int value)
{
   if (root == NULL)
   {
      return false;
   }
   if (value < root->value)
   {
      return search_node(root->left, value);
   }
   else if (value > root->value)
   {
      return search_node(root->right, value);
   }
   else
   {
      return true;
   }
}
void preOrder(struct binary_search_tree *root)
{
   if (root == NULL)
      return;
   printf("%d ", root->value);
   preOrder(root->left);
   preOrder(root->right);
}
//--------------------------findMax(root)------------------------\n");
int findMax(struct binary_search_tree *root)
{
   // statements
   while (root->right != NULL)
   {
      root = root->right;
   }

   return root->value;
}
//--------------------------findMin(root)------------------------\n");
int findMin(struct binary_search_tree *root)
{
   while(root->left != NULL)
   {
      root = root->left;
   }
   return root->value;
}
//--------------------------findSum(root)------------------------\n");
int findSum(struct binary_search_tree *root)
{
   //struct binary_search_tree *temp;
   int sum = 0;
   if (root == NULL)
      return;
   sum = root->value + findSum(root->left) + findSum(root->right);
   return (sum);
}
void inOrder(struct binary_search_tree *root)
{
   if (root == NULL)
      return;
   inOrder(root->left);
   printf("%d ", root->value);
   inOrder(root->right);
}
void postOrder(struct binary_search_tree *root)
{
   if (root == NULL)
      return;
   postOrder(root->left);
   postOrder(root->right);
   printf("%d ", root->value);
}
void breathFirst(struct binary_search_tree *root)
{
   struct binary_search_tree *temp;
   emptyQueue();
   enqueue(root);
   while (!isEmpty())
   {
      temp = dequeue();
      printf("%d ", temp->value);
      if (temp->left != NULL)
      {
         enqueue(temp->left);
      }
      if (temp->right != NULL)
      {
         enqueue(temp->right);
      }
   }
}