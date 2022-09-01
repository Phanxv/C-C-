#include <stdio.h>
#include <stdbool.h>
struct node{
    int info;
    struct node *next;
} *head = NULL;
int s = 0;
int size() {
	return s;
}
bool isEmpty(){
	return s == 0;
}
void insert_node_begin(int num) {
	struct node *inst; 
	inst = (struct node *) malloc( sizeof(struct node));  
	inst->info = num;  
	inst->next = head; 
	head = inst;	 
	s++;		 
}
void insert_node_end(int num){
	struct node *inst, *prev;
	inst = (struct node *)malloc(sizeof(struct node));
	inst->info = num;
	prev = head;
	if (prev != NULL){
		while(prev->next != NULL){
			prev = prev->next;
		}
		inst->next = NULL;
		prev->next = inst;
	} else {
		inst->next = NULL;
		head = inst;
	}
	s++;	
}
int insert_at_position(int num, int p){
	if(p < 1 || p > s+1){
		return -1;
	}
	struct node *inst, *prev, *follow;
	inst = (struct node *) malloc(sizeof(struct node));  
	inst->info = num;
	if(p == 1){  
 		insert_node_begin(num);
	} else if(p == s+1) {
		insert_node_end(num);
	} else {
		follow = head;
		int i;
		for(i = 1; i < p; i++){
			prev = follow;
			follow = follow->next;
		}
		prev->next = inst;
		inst->next = follow;
		s++;
	}
 	return p;
}
int set(int p, int num){
	if(p < 1 || p > s || isEmpty()){
		return -1;
	}
	int i, value = 0;
	struct node *prev = head;
	for(i = 1; i < p; i++){
			prev = prev->next;
	}
	value = prev->info;
	prev->info = num;
	return value;	
}
int delete_node_begin(){
	int value = -1;
	struct node *del = head;	
	if(del != NULL){
		value = del->info;
		head = head->next;
		free(del);
		s--;	
	}
	return value;
}
int delete_node_end(){
	int value = -1;
	struct node *del, *prev;
	if(head != NULL){
		del = head;
		prev = head;
		while(del->next != NULL){
			prev = del;
			del = del->next;
		}
		value = del->info;
		prev->next = del->next;
		free(del);
		s--;	
		if(s == 0){  
			head = NULL;
		}
	}
	return value;
}
int delete_node_info(int num){
	int value = -1;
	struct node *del, *prev;
	if(head != NULL){
		prev = head;
		del = head;
		while(del->next != NULL && del->info != num){
			prev = del; 
			del = del->next;
		}
		if(del->info == num){
			value = del->info;
			if(del == head){
				head = head->next;
			} else if(del->next == NULL){
				prev->next = NULL;
			} else if(del->next != NULL){
				prev->next = del->next;
			}
			free(del);
			s--;
		}
	}
	return value;
}
int delete_node_position(int p){
	if(p < 1 || p > s){
		return -1;
	}
	int value = -1;
	struct node *del, *prev;
	if(p == 1){  
 		value = delete_node_begin();
	} else if(p == s) {
		value = delete_node_end();
	} else {
		del = head;
		int i;
		for(i = 1; i < p; i++){
			prev = del;
			del = del->next;
		}
		value = del->info;
		prev->next = del->next;
		free(del);
		s--;
	}
 	return value;
}
int get(int p){
	if(p < 1 || p > s){
		return -1;
	}
	struct node *prev = head;
	int value = -1, i;
	if(prev != NULL){
		for(i = 1; i < p; i++) {			
		    prev = prev->next;
		}
		value = prev->info;
    }
    return value;
}
//-------------------------findMax()-------------------------//
int findMax(){			 
 	struct node *prev = head;
	int max = prev->info;
	while(prev != NULL){	
		if(prev->info > max){
			max = prev->info;
		}
		prev = prev->next;
	}
	return max;
}
//----------------------------------------------------------//
void display(){
	struct node *prev = head;	
	while(prev != NULL){
		printf("%d ", prev->info);
		prev = prev->next;
	}
	printf("\n");
}
