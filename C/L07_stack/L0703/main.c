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

int main(){
    char postfix_exp[100];
    int i,num1,num2,val;
    scanf("%s",postfix_exp);
    for(i=0;i<strlen(postfix_exp);i++)
    {
        if(isdigit(postfix_exp[i]))
        {
            push(postfix_exp[i]-48);
        }
        if(is_operator(postfix_exp[i]))
        {
            if(!isEmpty())
            {
                num1 = pop();
                num2 = pop();
                switch (postfix_exp[i]){
                    case '*':
                        val = num2 * num1;
                        break;
                    case '/':
                        val = num2 / num1;
                        break;
                    case '+':
                        val = num2 + num1;
                        break;
                    case '-':
                        val = num2 - num1;
                        break;
                }
                push(val);
            }
        }
    }
    printf("%d",pop());
}
