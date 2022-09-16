#include <string.h>
#include "stackG2.h"
#include "linearQueueG2.h"
struct node *array;
int N = 0;
void createGraph(int V){
	int i;
    array = calloc(V, sizeof(struct node));
    N = V;
    for (i = 0; i < V; ++i){
        array[i].next = NULL;
        array[i].prior = NULL;
    }
}
struct node* newNode(char *name){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->prior = NULL;
    newNode->next = NULL;
    return newNode;
}
void addNode(int src, char *name){
	if(src < 0 || src > N){
		return;
	}
	strcpy(array[src].name, name); 
}
void addEdge(char *src, char *dest){
    struct node* check = NULL;
    struct node* inst = newNode(dest);
    int i;
    for (i = 0; i < N; ++i){
    	if(strcmp(src, array[i].name) == 0){	
    		if(array[i].next == NULL){
    		   array[i].next = inst;
    		   inst->prior = &array[i];		
			} else {
                check = array[i].next;
                while (check->next != NULL) {
                   check = check->next;
                }
                check->next = inst;
                inst->prior = check;
            }
            break;
		}
	}
}
void printGraph() {
    int i;
    struct node *prev;
    for (i = 0; i < N; ++i) {
    	prev = array[i].next;
        printf("\n Adjacency list of vertex %s\n", array[i].name);
        while (prev != NULL) {
            printf("-> %s ", prev->name);
            prev = prev->next;
        }       
        printf("\n");
    }
}
void printVertex() {
    int i;
    struct node *prev;
    printf("\nVertex : {");
    for (i = 0; i < N; ++i) {
    	if(i < N-1)
          printf("%s, ", array[i].name);
        else if(i == N-1){
          printf("%s}", array[i].name);	
		}
    }
    printf("\n");
}
void depthFirstTraversal(){
	if(N > 0){
		char x[N][10], out[N][10];
		int i = 0, j, n = 0;
		emptyStack();
		struct node *inst = newNode(array[i].name);
		struct node *temp, *prev;
		push(inst);
		strcpy(x[n], array[i].name);
		n++;
		while(!stEmpty()){
			temp = pop();
			strcpy(out[i], temp->name);
			i++;
			for(j = 0; j < N; j++){
			   if(strcmp(temp->name, array[j].name) == 0){
			   	  if(array[j].next != NULL){
			   	  	  	prev = array[j].next;
                      	while (prev->next != NULL) {
                         	prev = prev->next;
                      	}
                      	while (prev != NULL) {
                      		int i;
                      		bool flag = false;
                      		for(i = 0; i < n; i++){
                      			if(strcmp(x[i], prev->name ) == 0){
                      				flag = true;
                      				break;
								}
							}
                      		if(!flag){
                      			push(prev);
                      			strcpy(x[n], prev->name);
                      			n++;
							}
                         	prev = prev->prior;
                      	}
				  }
				  break;
			   }	
			}
		}
		printf("\nDepth First Traversal:\n");
		for(j = 0; j < N; j++){
			printf("%s ", out[j]);
		}
	}
}
void breadthFirstTraversal(){
	if(N > 0){
		char x[N][10], out[N][10];
		int i = 0, j, n = 0;
		struct node *temp, *prev;
		struct node *inst = newNode(array[i].name);		
		emptyQueue();
		enqueue(inst);
		strcpy(x[n], array[i].name);
		n++;
		while(!qEmpty()){
			temp = dequeue();
			strcpy(out[i], temp->name);
			i++;
			for(j = 0; j < N; j++){
			   if(strcmp(temp->name, array[j].name) == 0){
			   	  if(array[j].next != NULL){
			   	  	  	prev = array[j].next;
                      	while (prev != NULL) {
                      		int i;
                      		bool flag = false;
                      		for(i = 0; i < n; i++){
                      			if(strcmp(x[i], prev->name ) == 0){
                      				flag = true;
                      				break;
								}
							}
                      		if(!flag){
                      			enqueue(prev);
                      			strcpy(x[n], prev->name);
                      			n++;
							}
                         	prev = prev->next;
                      	}
				  }
				  break;
			   }	
			}
		}
		printf("\nBreadth First Traversal:\n");
		for(j = 0; j < N; j++){
			printf("%s ", out[j]);
		}
	}
}
