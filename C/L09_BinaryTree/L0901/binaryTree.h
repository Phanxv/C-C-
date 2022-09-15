#include "linearQueue1.h"
// Create node
struct node *newNode(int value) {
  struct node *inst = (struct node *) malloc(sizeof(struct node));
  inst->data = value;
  inst->left = inst->right = NULL;
  return inst;
}
// Preorder Traversal
void preorder(struct node *root) {
    if(root != NULL) {
      printf("%d ", root->data);
      preorder(root->left);
      preorder(root->right);
	}
}
// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}
// Postorder Traversal
void postorder(struct node *root) {
    if(root != NULL) {
      postorder(root->left);
      postorder(root->right);    
      printf("%d ", root->data);
	}
}
// Breath first Traversal
void breathFirst(struct node *root) {
    struct node* temp;
    if(root == NULL){
    	return;
	}
    emptyQueue();
    enqueue(root);
    while(!isEmpty()){	
        temp = dequeue();
        printf("%d ", temp->data);
        if(temp->left != NULL) {
            enqueue(temp->left);
        }
        if(temp->right != NULL) {
            enqueue(temp->right);
        }
    } 
}
// Insert node
int insert_node(struct node *root, int value) {  
    struct node* temp;
    int flag = -1;
    emptyQueue();
    enqueue(root);
    while (!isEmpty()) {
            temp = dequeue();
            if (temp->left == NULL) {
                temp->left = newNode(value);
                flag = 0;
                break;
            }
            else {
                enqueue(temp->left);
 			}
            if (temp->right == NULL) {
                temp->right = newNode(value);
                flag = 0;
                break;
            }
            else {
                enqueue(temp->right);
            }
        }
    return flag;
}
//Finde node
struct node *find_node(struct node *root, int value) {  
    struct node *temp, *tmp;
    emptyQueue();
    enqueue(root);
    while (!isEmpty()) {
            temp = dequeue();
            if (temp->left != NULL) {
                tmp = temp->left;
                if(tmp->data == value){
                	return temp;
				} else {
                	enqueue(temp->left);
                }
 			}
            if (temp->right != NULL) {
                tmp = temp->right;
                if(tmp->data == value){
                	return temp;
				} else {
                	enqueue(temp->right);
                }
        	}
        }
    return NULL;
}
// Delete node
int delete_copying(struct node *root, int value) {  
    struct node *temp, *tmp, *follow, *prev;
    int flag = -1;
    emptyQueue();
    enqueue(root);
    while (!isEmpty()) {
            temp = dequeue();
            if(temp->data == value){
            	if (temp->right != NULL) {
                	follow = temp;
					while(follow->right != NULL){
						prev = follow;
						follow = follow->right;
					}
					temp->data = follow->data;
					prev->right = follow->left;
					free(follow);
                	flag = 0;
                	break;
            	} else if(temp->left != NULL){
                	follow = temp;
					while(follow->left != NULL){
						prev = follow;
						follow = follow->left;
					}
					temp->data = follow->data;
					prev->left = follow->right;
					free(follow);
                	flag = 0;
                	break;            		           		
				} else if(temp->left == NULL && temp->right == NULL){					
					if(root->data == value){
						return -2;
    					break;
					} else {
						prev = find_node(root, value);
						if(prev->left != NULL){
							tmp = prev->left;
							if(tmp->data == value){
								prev->left = NULL;
							}
						} 
						if(prev->right != NULL){
							tmp = prev->right;
							if(tmp->data == value){
								prev->right = NULL;
							}
						}
						free(temp);						
					}
                	flag = 0;
                	break;				}
 			} else {
            	if (temp->left != NULL) {
                	enqueue(temp->left);
 				}
            	if (temp->right != NULL) {
                	enqueue(temp->right);
            	} 				
			}
        }
    return flag;
}