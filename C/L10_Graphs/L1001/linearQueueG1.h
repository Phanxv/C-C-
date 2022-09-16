#include <stdio.h>
#include <stdbool.h>
int arrQ[100];
int s = 0;
int N = 99;
int Rear = -1;
int gSize(){
	return s;
}
bool qEmpty(){
	return Rear == -1;
}
bool qFull(){
	return Rear == N;
}
void emptyQueue(){
	Rear = -1;
	s = 0;
}
int enqueue(int data) {
	int value = -1;
    if (!qFull()){
        Rear = Rear + 1;
        arrQ[Rear] = data;
		value = data;
        s++;
    }
    return value;
}
int dequeue() {
	int i = 0, value = -1;
    if (!qEmpty()){
 		value = arrQ[0];
 		for(i = 0; i < Rear; i++){
 			arrQ[i] = arrQ[i+1];
		}
		s--;
		Rear--;
    }
    return value;
}
void qDisplay(){
	int i = 0;
	if(!qEmpty()){
		for(i = 0; i < s; i++){
			printf("%d ", arrQ[i]);
		}
		printf("\n");
	}
}