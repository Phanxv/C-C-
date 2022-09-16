#include <stdio.h>
#include <stdbool.h>
#define QN 99
int s = 0;
int Rear = -1;
struct node* arr[100];
//--------------------------
void emptyQueue(){
	Rear = -1;
	s = 0;
}
int getSize(){
	return s;
}
bool qEmpty(){
	bool flag = false;
	if(Rear == -1) {
		flag = true;
	}
	return flag;
}
bool qFull(){
	return Rear == QN;
}
int enqueue(struct node* nd) {
	int vl = -1;
    if (!qFull()){
        Rear = Rear + 1;
        arr[Rear] = nd;
        s++;
        vl = 0;
    }
    return vl;
} 
struct node* dequeue() {
	int i = 0;
	struct node *nd = NULL;
    if (!qEmpty()){
 		nd = arr[0];
 		for(i = 0; i < Rear; i++){
 			arr[i] = arr[i+1];
		}
		s--;
		Rear--;
    }
    return nd;
}
void qdisplay(){
	int i = 0;
	if(!qEmpty()){
		for(i = 0; i <= Rear; i++){
			printf("%s ", arr[i]->name);
		}
	}
}
