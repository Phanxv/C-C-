#include <stdio.h>
#include "doublyLinkedList.h"
int main()
{
    int menu, num, p;
    do
    {
        printf("\nMenu 1 insert_node_begin(num)\n");
        printf("Menu 2 insert_node_end(num)\n");
        printf("Menu 3 insert_at_position(num,p)\n");
        printf("Menu 4 set(p,e)\n");
        printf("Menu 5 delete_node_begin()\n");
        printf("Menu 6 delete_node_end()\n");
        printf("Menu 7 delete_node_position(p)\n");
        printf("Menu 8 delete_node_info(num)\n");
        printf("Menu 9 display()\n");
        printf("Menu 10 findMin()\n");
        printf("Menu 11 exit\n");
        printf("Choose : ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            printf("---insert_node_begin(num)---\n");
            printf("Enter number : ");
            scanf("%d", &num);
            insert_node_begin(num);
            break;
        case 2:
            printf("---insert_node_end(num)---\n");
            printf("Enter number : ");
            scanf("%d", &num);
            insert_node_end(num);
            break;
        case 3:
            printf("---insert_at_position(num,p)---\n");
            printf("Enter number : ");
            scanf("%d", &num);
            printf("Enter position : ");
            scanf("%d", &p);

            printf("P = %d\n", insert_at_position(num, p));
            break;
        case 4:
            printf("------set(p, e)-----\n");
            printf("Enter number : ");
            scanf("%d", &num);
            printf("Enter position : ");
            scanf("%d", &p);
            printf("P = %d\n", set(p, num));
            break;
        case 5:
            printf("--delete_node_begin()--\n");
            printf("Data = %d\n", delete_node_begin());
            break;
        case 6:
            printf("--delete_node_end()--\n");
            printf("Data = %d\n", delete_node_end());
            break;
        case 7:
            printf("---delete_node_position(p)---\n");
            printf("Enter position : ");
            scanf("%d", &p);
            printf("Data = %d\n", delete_node_position(p));
            break;
        case 8:
            printf("--delete_node_info(num)--\n");
            printf("Enter number : ");
            scanf("%d", &num);
            printf("Data = %d\n", delete_node_info(num));
            break;
        case 9:
            printf("------display()-----\n");
            display();
            break;
        case 10:
            printf("------findMin()-----\n");
            printf("Min= %d\n", findMin());
            break;
        case 11:
            printf("Good bye\n");
        }
    } while (menu != 11);
    return 0;
}