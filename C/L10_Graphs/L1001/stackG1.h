#include <stdio.h>
#include <stdbool.h>
int data[100];
int size = 0;
int getSize(){
	return size;
}
bool isEmpty(){
	return size == 0;
}
bool isFull(){
 	return size == 100;
}
void emptyStack(){
	size = 0;
}
int top(){
	if(!isEmpty()){
		return data[size-1];
	}
	return -1;
}
int push(int value){
	if(!isFull()){
		data[size]=value;
		size++;
	}else {
		value = -1;
	}
	return value;
}
int pop(){
	int value = -1;
	if(!isEmpty()){
		value = data[size-1];
		data[size-1]=0;
		size--;
	}
	return value;
}
void display(){
	if(!isEmpty()){
		int i = 0;
		for(i = 0;i < size; i++){
			printf("%d ", data[i]);
		}
	}
}