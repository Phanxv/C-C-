#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <ctype.h>

int is_operator(char sym)
{
	if(sym == '^' || sym == '*' || sym == '/' || sym == '+' || sym =='-')
		return 1;
	else
		return 0;
}

int precedence(char ch) {
    if(ch == '+' || ch == '-')
        return 1;              
    else if(ch == '*' || ch == '/')
        return 2;          
    else if(ch == '^') 
        return 3;         
    else 
        return 0;
    
}

int main(){
    int i,j=0;
    char infix[100], postfix[100],x;
    printf("Enter infix : ");
    scanf("%s",infix);
    for(i=0;i<strlen(infix);i++)
    {
        if(infix[i] == '(')
        {
            push(infix[i]);
        }
        if(isalpha(infix[i])||isdigit(infix[i]))
        {
            postfix[j] = infix[i]; j++;
        }
        if(is_operator(infix[i]))
        {
            x = pop();
            while(is_operator(x) == 1 && precedence(x)>= precedence(infix[i])) 
            {
                postfix[j] = x; j++;
                x = pop();
            }
            push(x);
            push(infix[i]);
        }
        if(infix[i] == ')'){
            x = pop();
            while(x != '(') {
                postfix[j] = x; j++;
                x = pop();
            }
        }
    }
    while(!isEmpty()){
        postfix[j] = pop(); j++;
    }
    postfix[j++] = '\0';
    printf("%s",postfix);
}