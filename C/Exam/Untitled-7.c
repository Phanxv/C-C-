#include <stdio.h>
#include <string.h>

int main(void) {
    char usrInput[50];
    printf("Enter a string to be decrypted: ");
    gets(usrInput);
    for(int i=0; i<=strlen(usrInput) ;i++) {

        if (usrInput[i]>=97 && usrInput[i]<110){
            usrInput[i] += 13;
        }
        else if (usrInput[i]>=110 && usrInput[i]<=122){
            usrInput[i] -= 13;
        }
    }
    printf("Decrypted text : %s", usrInput);
}