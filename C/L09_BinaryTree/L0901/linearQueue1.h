#include <stdio.h>
#include <stdbool.h>
#define N 99
int size = 0;
int Rear = -1;
struct node {
  int data;
  struct node *left, *right;
};
struct node* arr[100];
//--------------------------
void emptyQueue(){
	Rear = -1;
	size = 0;
}
int getSize(){
	return size;
}
bool isEmpty(){
	bool flag = false;
	if(Rear == -1) {
		flag = true;
	}
	return flag;
}
bool isFull(){
	return Rear == N;
}
int enqueue(struct node* nd) {
	int vl = -1;
    if (!isFull()){
        Rear = Rear + 1;
        arr[Rear] = nd;
        size++;
        vl = 0;
    }
    return vl;
} 
bool search(int value){
	bool flag = false;
	int i = 0;
	if(!isEmpty()){
		for(i = 0; i <= Rear; i++){
			if(arr[i]->data == value){
				flag = true;
				break;
			}
		}
	}
	return flag;
}
struct node* dequeue() {
	int i = 0;
	struct node *nd = NULL;
    if (!isEmpty()){
 		nd = arr[0];
 		for(i = 0; i < Rear; i++){
 			arr[i] = arr[i+1];
		}
		size--;
		Rear--;
    }
    return nd;
}
void display(){
	int i = 0;
	if(!isEmpty()){
		for(i = 0; i <= Rear; i++){
			printf("%d ", arr[i]->data);
		}
	}
}