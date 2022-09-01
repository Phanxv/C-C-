#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(){
    char str_input[100];
    int i;
    printf("Enter String : ");
    scanf("%s",str_input);
    for(i=0;i<strlen(str_input);i++)
    {
        if(str_input[i]=='('||str_input[i]=='['||str_input[i]=='{')
        {
            push(str_input[i]);
        }
        if(str_input[i]==')'||str_input[i]==']'||str_input[i]=='}')
        {
            if(!isEmpty())
            {
                switch (str_input[i])
                {
                case ')':
                    '(' == pop() ? printf("True String") : printf("Wrong String");
                    break;
                case ']':
                    '[' == pop() ? printf("True String") : printf("Wrong String");
                    break;
                case '}':
                    '{' == pop() ? printf("True String") : printf("Wrong String");
                    break;
                default:
                    break;
                }
            }
            else
            {
                printf("Wrong String");
            }
        }
    }
    isEmpty() ? : printf("Wrong String");
    return 0;
}