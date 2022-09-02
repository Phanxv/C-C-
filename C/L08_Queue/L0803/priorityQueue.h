#include <stdio.h>
#include <stdbool.h>
int arr[100];
int N = 99;
int Rear = -1;
int s = 0;
bool isEmpty(){
   return Rear == -1;
}
bool isFull(){
   return Rear == N;
}
int size(){
   return s;
}
int top() {
	if(!isEmpty()){
   		return arr[0];
	}
	return -1;
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
int enqueuePQ(int data){
   int i = 0, value = -1;
   if(!isFull()){
      if(isEmpty()){
			Rear = 0;
			arr[Rear] = data;
      }else{
         for(i = Rear; i >= 0; i-- ){
            if(data > arr[i]){
               arr[i+1] = arr[i];
            }else{
               break;
            }
         }
         arr[i+1] = data;
		 Rear++;
         value = data;
      }
      s++;
   }
   return value;
}
int dequeue(){
	int value = -1, i = 0;
	if(!isEmpty()){
		value = arr[0];
		for(i = 0; i < Rear; i++){
			arr[i] = arr[i+1];
		}
		Rear--;
		s--;
	}
   return value;
}
int maxIndex () {
    int index = -1, i;
    if(!isEmpty()) {
      	int min = arr[0];
        index = 0;
      	for(i = 1; i <= Rear; i++){
          if(arr[i] > min){
            min = arr[i];
            index = i;
          }
        }
    }
    return index;
}
int dequeuePQ() {
    int value = -1, i;
    if(!isEmpty()){
      	int index = maxIndex();
		value = arr[index];
		for(i=index; i < Rear; i++){
            arr[i] = arr[i+1];
		}
        Rear--;
		s--;
    }
    return value;
}
//------------------------------------------------------search(num)-----------------------------------------//
int search(int data){

    //statements
	return -1;
}
//--------------------------------------------------------------------------------------------------------------------//
void display(){
	int i = 0;
	if(!isEmpty()){
		for(i = 0; i <= Rear; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}