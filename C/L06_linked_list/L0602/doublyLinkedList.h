#include <stdio.h>
#include <stdbool.h>
struct node{
    int info;
    struct node *prior;
    struct node *next;
} *head = NULL, *last = NULL;
int s = 0;
int size(){
	return s;
}
bool isEmpty(){
	return s == 0;
}
void insert_node_begin(int num){
	struct node *inst;
	inst = (struct node *) malloc(sizeof(struct node));
	inst->info = num;
	if(head == NULL){
		inst->prior = NULL;
		inst->next = NULL;
		head = inst;
		last = inst;
	}
	else {
		inst->prior = NULL;
		inst->next = head; 
		head->prior = inst;
		head = inst;
	}
	s++;
}
void insert_node_end(int num){
	struct node *inst;
	inst = (struct node *)malloc(sizeof(struct node));
	inst->info = num;
	if(last != NULL){
		inst->prior = last;
		inst->next = NULL;
		last->next = inst;		
		last = inst;
	} else {
		inst->prior = NULL;
		inst->next = NULL;
		head = inst;
		last = inst;
	}
	s++;
}
int insert_at_position(int num, int p){
	if(p < 1 || p > s + 1){
		return -1;
	}
	struct node *inst, *prev, *follow;
	inst = (struct node *) malloc(sizeof(struct node));  
	inst->info = num;
	if(head == NULL) {  
 		insert_node_begin(num);
	} else if(p == s + 1) {
		insert_node_end(num);
	} else {
		prev = head;
		follow = head;
		int i;
		for(i = 1; i < p; i++){
			prev = follow;
			follow = follow->next;
		}
		prev->next = inst;
		inst->prior = prev;
		inst->next = follow;
		follow->prior = inst;
		s++;
	}
 	return p;
}
int delete_node_begin(){
	int value = -1;
	struct node *del, *prev;
	del = head;
	if(del != NULL){
		value = del->info;
		if(del->next != NULL){
			head = head->next;
			head->prior = NULL;
		} else {
			head = NULL;
			last = NULL;
		}
		free(del);
		s--;	
	}
	return value;
}
int delete_node_end( ) {
	int value = -1;
	struct node *del = last;
	if (del != NULL) {
       	value = del->info;
       	if (del->prior != NULL) {
       		last = last->prior;
       		last->next = NULL;
	   	} else {
	   		head = NULL; 
			last = NULL;
	  	}
       	free(del);
	   	s--;
	}
	return value;
}
int delete_node_info(int num){
	int value = -1;
	struct node *del, *prev;
	del = head;
	if(del != NULL){		
		prev = head;
		while(del->next != NULL && del->info != num){
			prev = del; 
			del = del->next;
		}
		if(del->info == num){
			value = del->info;
			if(del == head) {
				delete_node_begin(); 
			} else if(del->next == NULL){
				delete_node_end(); 
			} else {
				prev->next = del->next;
				del->next->prior = prev;
				s--;
			    free(del);
			}
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
		del->next->prior = prev; 
		s--; 
		free(del);		
	}
 	return value;
}
int set(int p, int num){
	if(p < 1 || p > s){
		return -1;
	}
	int value = -1;
	struct node *prev = head;
	int i;
	for(i = 1; i < p; i++){
		prev = prev->next;
	}
	value = prev->info;
	prev->info = num;		
 	return value;
}
int get(int p){
	if(p < 1 || p > s){
		return -1;
	}
	int value = -1;
	struct node *prev = head;
	int i;
	for(i = 1; i < p; i++){
		prev = prev->next;
	}
	value = prev->info;	
 	return value;
}
//-----------------------------findMin()---------------------------//
int findMin(){
	struct node *prev = head;
	int min = prev->info;
	while(prev != NULL){	
		if(prev->info < min){
			min = prev->info;
		}
		prev = prev->next;
	}
	return min;
}
//----------------------------------------------------------------//
void display(){
	struct node *prev;	
	prev = head;
	while(prev != NULL){
		printf("%d ", prev->info);
		prev = prev->next;
	}
	printf("\n");
}
