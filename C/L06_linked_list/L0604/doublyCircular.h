#include <stdio.h>
#include <stdbool.h>
struct node{
    int info;
    struct node *prior;
    struct node *next;
} *head = NULL;
int s = 0;
bool isEmpty(){
	return s == 0;
}
int size(){
	return s;
}
void insert_node_begin(int num){
	struct node *inst;
	inst = (struct node *) malloc(sizeof(struct node));
	inst->info = num;
	if(head == NULL){
		inst->prior = inst;
		inst->next = inst;
		head = inst;			
	}
	else {
		inst->next = head; 
		inst->prior = head->prior;		
		head->prior->next = inst;
		head->prior = inst;
		head = inst;
	}
	s++;
}
void insert_node_end(int num){
	struct node *inst, * prev;
	inst = (struct node *)malloc(sizeof(struct node));
	inst->info = num;
	if(head == NULL){
		inst->prior = inst;
		inst->next = inst;
		head = inst;
	} else { 
		inst->prior = head->prior;		
		head->prior->next = inst;
		head->prior = inst;
		inst->next = head;
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
	if(p == 1){  
 		insert_node_begin(num);
	} else if(p == s + 1) {
		insert_node_end(num);
	} else {
		follow = head;
		prev = head;
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
	struct node *del;	
	if(head != NULL){
		del = head;	
		value = del->info;
		if(head->next == head){
			head = NULL;
		} else {
			head = head->next;
			head->prior = del->prior;
			del->prior->next = head;
		}
		free(del);
		s--;
	}
	return value;
}
int delete_node_end(){
	int value = -1;
	struct node *del, *prev, *follow;
	if(head != NULL){
		del = head->prior;
		value = del->info;
		if(head->next == head){
			head = NULL;
		} else {
			head->prior = del->prior;
			del->prior->next = head;
		}
		free(del);
		s--;
	}
	return value;
}
int delete_node_info(int num){
	int value = -1;
	struct node *prev, *follow;
	if(head != NULL){
		follow = head;
		prev = head->prior;
		while(follow->next != head && follow->info != num){
			prev = follow; 
			follow = follow->next;
		}
		if(follow->info == num){
			value = follow->info;
			if(head->next == head){
				head = NULL;
			} else {
				prev->next = follow->next; 
				follow->next->prior = prev;
				if(follow == head){
					head = head->next;
				}
			}
			s--;
			free(follow);
		}
	}
	return value;
}
int delete_node_position(int p){
	if(p < 1 || p > s || isEmpty()){
		return -1;
	}
	int value = -1;
	struct node *del, *prev, *follow;
	if(p == 1){  
 		delete_node_begin();
	} else if(p == s) {
		delete_node_end();
	} else {
		follow = head;
		int i;
		for(i = 1; i < p; i++){
			prev = follow;
			follow = follow->next;
		}
		prev->next = follow->next;
		follow->next->prior = prev; 
		s--;
		free(follow);		
	}
 	return p;
}
int get(int p){
	if(p < 1 || p > s || isEmpty()){
		return -1;
	}
	struct node *prev;
	int value = -1, i;
	if(head != NULL){
		prev = head;
		for(i = 1;i < p; i++){
			prev = prev->next;
		}
		value = prev->info;
	}
	return value;
}
int set(int p, int num){
	if(p < 1 || p > s || isEmpty()){
		return -1;
	}
	struct node *prev;
	int value = -1, i;
	if(head != NULL){
		prev = head;
		for(i = 1;i < p; i++){
			prev = prev->next;
		}
		value = prev->info;
		prev->info = num;
	}
	return value;
}
int findMax(){
	int mx = -1, i;
	struct node *prev;
	if(head != NULL){
		prev = head;
		mx = prev->info;
		prev = head->next;		
		for(i = 2; i <= s; i++) {
			if(prev->info > mx){
				mx = prev->info;
			}
			prev = prev->next;
		}
	}
	return mx;
}
void display(){
	struct node *prev;	
	int i = 1;
	if(head != NULL){
		prev = head;
		for(i = 1; i <= s; i++){
			printf("%d ", prev->info);
			prev = prev->next;
		}
		printf("\n");
	}
}
