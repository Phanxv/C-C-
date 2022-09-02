#include <stdio.h>
#include "circularQueue.h"

int main()
{
    int menu, num;
    do{
       printf("Menu 1 : enqueue(num)\n");
       printf("Menu 2 : dequeue()\n");
       printf("Menu 3 : search(num)\n");
       printf("Menu 4 : display()\n");
       printf("Menu 5 : exit\n");
       printf("Choose : ");
       scanf("%d", &menu);
       switch(menu){
            case 1 : printf("-----enqueu(num)------\n");
                     printf("Enter number : ");
                     scanf("%d", &num);
                     enqueue(num);
                     break;
            case 2 : printf("-----dequeue()------\n");
                     printf("Data : %d\n", dequeue());
                     break;
            case 3 : printf("-----search(num)------\n");
                     printf("Enter number : ");
                     scanf("%d", &num);
                     printf("index : %d\n", search(num));
                     break;
            case 4 : printf("-----display()------\n");
                     display();
                     break;
            case 5 : printf("Good bye\n");
       }
       printf("\n");
    }while(menu != 5);
    return 0;
}

