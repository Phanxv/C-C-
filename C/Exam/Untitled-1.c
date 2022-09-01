#include <stdio.h>
#include <string.h>

void inverseString(char *str,int length);

int main(){
    char usrInput[50];
   //char *ptr = usrInput;
    int length;
    printf("Enter String >> ");
    gets(usrInput);
    length = strlen(usrInput);
    printf("Inversed String = ");
    inverseString(usrInput,length);
}

void inverseString(char *str,int length){
    for(int i=length;i>=0;i--){
        printf("%c",str[i]);
    }
}