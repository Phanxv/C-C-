#include <stdio.h>
#include <stdbool.h>
struct node{
    int info;
    struct node *next;
} *last = NULL;
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
	if(last == NULL){
		last = inst; 
		last->next = last;		
	} else {
		inst->next = last->next;
		last->next = inst;
	} 
	s++;
}
void insert_node_end(int num){
	struct node *inst, * prev;
	inst = (struct node *)malloc(sizeof(struct node));
	inst->info = num;
	if(last == NULL){
		last = inst; 
		last->next = last;		
	} else {
		inst->next = last->next;
		last->next = inst;
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
	if(p == 1){ 
 		insert_node_begin(num);
	} else if(p == s + 1) {
		insert_node_end(num);
	} else {
		follow = last->next;
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
int delete_node_begin(){
	int value = -1;
	struct node *del;
	if(last != NULL){
		del = last->next;		
		value = del->info;
		if(del == last){
			last = NULL;
		} else {
			last->next = del->next;
		}
		free(del);
		s--;	
	}
	return value;
}
int delete_node_end(){
	int value = -1;
	struct node *prev, *follow;
	if(last != NULL){
		if(last->next == last){
			free(last);
			last = NULL;
		} else {
			prev = last;
			follow = last->next;
			while(prev->next != last){
				prev = follow;
				follow = follow->next;
			}
			value = follow->info;
			prev->next = follow->next;
			last = prev;
			free(follow);
		}
		s--;	
	}
	return value;
}
int delete_node_info(int num){
	int value = -1;
	struct node *prev, *follow;
	if(last != NULL){
		prev = last;
		follow = last->next;
		while(follow != last && follow->info != num){
			prev = follow; 
			follow = follow->next;
		}
		if(follow->info == num){
			value = follow->info;
			if(follow->next == follow){
				last = NULL;
			} else {
				prev->next = follow->next;
				if(follow == last){
					last = prev;	
				}				
			}
			free(follow);
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
	struct node *prev, *follow;
	if(p == 1){  
 		value = delete_node_begin();
	} else if(p == s) {
		value = delete_node_end();
	} else {
		follow = last->next;
		int i;
		for(i = 1; i < p; i++){
			prev = follow;
			follow = follow->next;
		}
		prev->next = follow->next;
		value = follow->info;
		free(follow);
		s--;
	}
 	return value;
}
int get(int p){
	if(p < 1 || p > s){
		return -1;
	}
	int value = 0, i;
	struct node *prev;
	if(last != NULL){
		prev = last->next;
		for(i = 1; i < p; i++){
			prev = prev->next;
		}
		value = prev->info;
	}
	return value;
}
int set(int p, int num){
	if(p < 1 || p > s){
		return -1;
	}
	int value = -1, i;
	struct node *prev;
	if(last != NULL){
		prev = last->next;
		for(i = 1; i < p; i++){
			prev = prev->next;
		}
		value = prev->info;
		prev->info = num;
	}
	return value;
}
//--------------------------search(num)----------------------//
int search(int num){
	struct node *prev;
	if(last != NULL){	
		prev = last->next;
		int i;
		for(i = 1; i <= s; i++){
			if(prev->info == num){
				return i;
			}
			prev = prev->next;
		}
	}
}
//----------------------------------------------------------//
void display(){
	struct node *prev;
	if(last != NULL){	
		prev = last->next;
		int i;
		for(i = 1; i <= s; i++){
			printf("%d ", prev->info);
			prev = prev->next;
		}
		printf("\n");
	}
}

