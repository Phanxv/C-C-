#include <stdio.h>
#include <stdbool.h>
int arr[100];
int s = 0;
int N = 99;
int Rear = -1;
int size(){
	return s;
}
bool isEmpty(){
	return Rear == -1;
}
bool isFull(){
	return Rear == N;
}
int enqueue(int data) {
	int value = -1;
    if (!isFull()){
        Rear = Rear + 1;
        arr[Rear] = data;
		value = data;
        s++;
    }
    return value;
}
//-----------------------------------------------search(data)-------------------------------------------------------------//
int search(int data){
	int i = 0;
	for(i=0;i<s;i++){
		if(arr[i]==data)
			return i;
	}
	return -1;
}
//----------------------------------------------------------------------------------------------------------------------------//
int dequeue() {
	int i = 0, value = -1;
    if (!isEmpty()){
 		value = arr[0];
 		for(i = 0; i < Rear; i++){
 			arr[i] = arr[i+1];
		}
		s--;
		Rear--;
    }
    return value;
}
void display(){
	int i = 0;
	if(!isEmpty()){
		for(i = 0; i < s; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}
