#include <stdio.h>
#include <stdbool.h>
struct node {
    char name[10];
    struct node *prior;
    struct node *next;
};
struct node* data[100];
int size = 0;
int stSize(){
	return size;
}
bool stEmpty(){
	return size == 0;
}
bool stFull(){
 	return size == 100;
}
void emptyStack(){
	size = 0;
}
struct node* top(){
	if(!stEmpty()){
		return data[size-1];
	}
	return NULL;
}
int push(struct node* nd){
	int value = -1;
	if(!stFull()){
		data[size]=nd;
		size++;
		value = 0;
	}
	return value;
}
struct node* pop(){
	struct node* value = NULL;
	if(!stEmpty()){
		value = data[size-1];
		data[size-1]=0;
		size--;
	}
	return value;
}
void display(){
	if(!stEmpty()){
		int i = 0;
		for(i = 0;i < size; i++){
			printf("%s ", data[i]->name);
		}
	}
}
