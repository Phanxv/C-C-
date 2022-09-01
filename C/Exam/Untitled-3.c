#include <stdio.h>

int main(){
    int arr[10] = {2,1,1,1,3,1,0,6,0,9};
    int odd[10], even[10];
    int i,j=0,k=0,minOdd=10,maxOdd=-10,minEven=10,maxEven=-10;
    printf("Student ID : ");
    for(i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    for(i=0;i<10;i++){
        if(arr[i]%2==0){
            even[j] = arr[i];
            j++;
        }
        else{
            odd[k] = arr[i];
            k++;
        }
    }
    printf("\nOdd number : ");
    for(i=0;i<6;i++){
        printf("%d ",odd[i]);
    }
    for(i=0;i<6;i++){
        if(odd[i]<minOdd){
            minOdd = odd[i];
        }
        if(odd[i]>maxOdd){
            maxOdd = odd[i];
        }
    }
    printf("\nMaximum : %d",maxOdd);
    printf("\nMinimum : %d",minOdd);
    printf("\nEven number : ");
    for(i=0;i<4;i++){
        printf("%d ",even[i]);
    }
    for(i=0;i<4;i++){
        if(even[i]<minEven){
            minEven = even[i];
        }
        if(even[i]>maxEven){
            maxEven = even[i];
        }
    }
    printf("\nMaximum : %d",maxEven);
    printf("\nMinimum : %d",minEven);
}