#include <stdio.h>

void cleanup(int arr[],int len);
void print_arr(int *arr,int len);

int main(){
    int dat[] = {-122, -45, -1, 7, 67, -65, 100, -124, 432, 523, 256, 255, 250};
    printf("Data before clean up : ");
    print_arr(dat,13);
    cleanup(dat,13);
    printf("\n");
    printf("Data after clean up : ");
    print_arr(dat,13);
}

void cleanup(int arr[],int len){
    int i;
    for(i=0;i<len;i++){
        if(arr[i]<0 || arr[i]>255){
            arr[i] = 0;
        }
    }

}

void print_arr(int *arr,int len){
    int i;
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}