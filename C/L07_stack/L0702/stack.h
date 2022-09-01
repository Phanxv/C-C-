#include <stdio.h>
#include <stdbool.h>
int arr[100];
int top_index = -1;
int size(){
	return top_index + 1;
}
bool isEmpty(){
	return top_index == -1;
}
bool isFull(){
 	return top_index + 1 == 100;
}
int top(){
	return top_index;
}
int peek(){
	if(!isEmpty()){
		return arr[top_index];
	}
	return -1;
}
int push(int data) {
	if(!isFull()) {
        top_index++;
		arr[top_index] = data;
		return data;
	}
	return -1;
}
int pop(){
	int value = -1;
	if(!isEmpty()){
		value = arr[top_index];
		arr[top_index]=0;
		top_index--;
	}
	return value;
}
void display(){
	if(!isEmpty()){
		int i = 0;
		for(i = 0;i <= top_index; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}
