#include <stdio.h>
#include <stdbool.h>
int arr[5];
int N = 4;
int s = 0;
int Front = -1;
int Rear = -1;
int size(){
   return s;
}
int getFront(){
	return Front;
}
int getRear(){
	return Rear;
}
bool isEmpty(){
	return Rear == -1;
}
bool isFull(){
	if((Front == 0 && Rear == N) || (Rear + 1) == Front){
		return true;
	}
	return false;
}
int enqueue(int data){
	int value = -1;
	if(!isFull()){
		if(isEmpty()){
			Rear = 0;
			Front = 0;
		} else if(Rear == N){
			Rear = 0;
		} else {
			Rear++;
		}
		arr[Rear] = data;
		s++;
		value = data;
	}
	return value;
}
int dequeue(){
	int value = -1;
	if(!isEmpty()){
		value = arr[Front];
		if(Front == Rear){
			Front = -1;
			Rear = -1;
		} else if(Front == N){
			Front = 0;
		} else {
			Front++;
		}
		s--;
	}
	return value;
}
void display(){
	int i = 0, j = 0;
	if(!isEmpty()){
		i = Front;
		j = Rear;
		while(i != j){
			printf("%d ", arr[i]);
			if(i == N){
				i = 0;
			} else {
				i++;
			}
		}
		if(i == j){
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}
//------------------------------------------------------search(num)------------------------------------------------------------//
int search(int value){
	int i = 0, j = 0;
	if(!isEmpty()){
		i = Front;
		j = Rear;
		while(1){
			if(value == arr[i])
				return i;
			if(i == N){
				i = 0;
			} else {
				i++;
			}
		}
		return -1;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------//
