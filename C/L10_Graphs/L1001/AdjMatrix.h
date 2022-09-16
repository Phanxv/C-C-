#include <stdio.h>
#include <stdbool.h>
#include "stackG1.h"
#include "linearQueueG1.h"
int *arr;
int N;
void createMatrix(int n){
	int i;
	arr = calloc(n, sizeof(int));
	for(i = 0; i < n; i++){
		arr[i] = calloc(n, sizeof(int));
	}
	N = n;
}
void addEdge(int src, int dest){
    if(src < 1 || src > N || dest < 1 || dest > N){
    	return;
	}
	arr[(src-1) * N + (dest-1)] = 1;
}
void defaults(int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			arr[i*n+j]= 0;
		}
	}
}
bool check(int *ax, int value, int n){
	int i;
	bool flag = false;
	if(n > 0){
		for(i = 0;i < n; i++){
			if(ax[i] == value){
				flag = true;
				break;
			}
		}
	}
	return flag;
}
void depthFirstTraversal(){
	if(N > 0){
		int x[N], out[N], i = 0, j, temp = 0, n = 0;
		emptyStack();
		push(temp+1);
		x[n]=temp+1;
		n++;
		while(!isEmpty()){
			temp = pop();
			out[i] = temp;
			i++;
			temp = temp - 1;
			for(j = N-1; j >= 0; j--){
			   if(arr[temp*N+j] == 1){
			   	  if(!check(x, j+1, n)){
			   	  	 push(j+1);
			   	  	 x[n]=j+1;
					 n++;
				  }
			   }	
			}
		}
		for(j = 0; j < N; j++){
			printf("%d ", out[j]);
		}
	}
}
void breadthFirstTraversal(){
	if(N > 0){
		int x[N], out[N], i = 0, j, temp = 0, n = 0;
		emptyQueue();
		enqueue(temp+1);
		x[n]=temp+1;
		n++;
		while(!qEmpty()){
			temp = dequeue();
			out[i] = temp;
			i++;
			temp = temp - 1;
			for(j = 0; j < N; j++){
			   if(arr[temp*N+j] == 1){
			   	  if(!check(x, j+1, n)){
			   	  	 enqueue(j+1);
			   	  	 x[n]=j+1;
					 n++;
				  }
			   }	
			}
		}
		for(j = 0; j < N; j++){
			printf("%d ", out[j]);
		}
	}
}
void printfArr( int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ", arr[i*n+j]);
		}
		printf("\n");
	}	
}