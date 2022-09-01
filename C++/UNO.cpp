#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int allcard=104;

void DEX_OF_CARD (int dexofcard[]){
    int a=0, b, i, j;
    for (j=1;j<5;++j){
        for (i=1;i<25;++i,++a){
            dexofcard[a] = j*100 + i + 10;
        }
    }
    dexofcard[96] = 999;
    dexofcard[97] = 999;
    dexofcard[98] = 999;
    dexofcard[99] = 999;
    dexofcard[100] = 9999;
    dexofcard[101] = 9999;
    dexofcard[102] = 9999;
    dexofcard[103] = 9999;


    for (i=0;i<104;++i){
        j = rand()%104;
        b = dexofcard[i];
        dexofcard[i] = dexofcard[j];
        dexofcard[j] = b;
    }

}

void start(){
    printf("\n         |||||   |||||   ||||||||||  |||||   |||||||||||||         \n");
    printf("         |||||   |||||   ||||||||||  |||||   |||||||||||||         \n");
    printf("         |||||   |||||   |||||  |||  |||||   |||||   |||||         \n");
    printf("   -     |||||   |||||   |||||  |||  |||||   |||||   |||||     -   \n");
    printf("         |||||   |||||   |||||  |||  |||||   |||||   |||||         \n");
    printf("         |||||||||||||   |||||  ||||||||||   |||||||||||||         \n");
    printf("         |||||||||||||   |||||  ||||||||||   |||||||||||||         \n\n");

    printf("                          Tap to Start !!\n");
    printf("-------------------------------------------------------------------\n\n");

    getch();
}
void p1(){
    system("CLS");
system("color 2");
    printf("         |||||||||||               ||||||            \n");
    printf("         ||||   ||||                  |||            \n");
    printf("         ||||   ||||                  |||            \n");
    printf("   -     |||||||||||                  |||        -   \n");
    printf("         ||||                         |||            \n");
    printf("         ||||                         |||            \n");
    printf("         ||||            |||       |||||||||         \n\n");

    //printf("                          Tap to Start !!\n");
    printf("-----------------------------------------------------\n");

    getch();
}
void p2(){
    system("CLS");
system("color 4");
    printf("         |||||||||||               ||||||           \n");
    printf("         ||||   ||||              ||   |||          \n");
    printf("         ||||   ||||                  |||           \n");
    printf("   -     |||||||||||                 |||         -   \n");
    printf("         ||||                       |||             \n");
    printf("         ||||                      |||              \n");
    printf("         ||||            |||      |||||||||         \n\n");

    //printf("                          Tap to Start !!\n");
    printf("-----------------------------------------------------\n");

    getch();
}
void showcard (int x[],int y){
    int z, i;
    for (i=0;i<y;++i){
        z = x[i];

        if (z%100 == 00)  printf("  |%d|-",i+1);
        if (z%100 == 11 || z%100 == 12)  printf("  |%d| 1",i+1);
        if (z%100 == 13 || z%100 == 14)  printf("  |%d| 2",i+1);
        if (z%100 == 15 || z%100 == 16)  printf("  |%d| 3",i+1);
        if (z%100 == 17 || z%100 == 18)  printf("  |%d| 4",i+1);
        if (z%100 == 19 || z%100 == 20)  printf("  |%d| 5",i+1);
        if (z%100 == 21 || z%100 == 22)  printf("  |%d| 6",i+1);
        if (z%100 == 23 || z%100 == 24)  printf("  |%d| 7",i+1);
        if (z%100 == 25 || z%100 == 26)  printf("  |%d| 8",i+1);
        if (z%100 == 27 || z%100 == 28)  printf("  |%d| 9",i+1);
        if (z%100 == 29 || z%100 == 30)  printf("  |%d| STOP",i+1);
        if (z%100 == 31 || z%100 == 32)  printf("  |%d| REVERSE",i+1);
        if (z%100 == 33 || z%100 == 34)  printf("  |%d| +2",i+1);

        if (z/100 == 1)  printf(" Green");
        if (z/100 == 2)  printf(" Blue");
        if (z/100 == 3)  printf(" Red");
        if (z/100 == 4)  printf(" Yellow");
        if (z/100 == 9)  printf("  |%d| Rainbow",i+1);
        if (z/100 == 99) printf("  |%d| +4!!",i+1);
        //printf("      %d",x[i]);
        printf("\n");
        }
    }
void runcard (int x[],int y){

    int i;
    for (i=0;i<y;++i){
        x[i] = x[i+1];
    }
//    x[allcard] = 0;
}


int main()
{
    int i, ans, stop=1, check=0, round=0, card_p1=6, card_p2=6, card_table=1;
    int dexofcard[allcard], p1_card[card_p1], p2_card[card_p2], table_card[card_table];
    srand(time(0));

    DEX_OF_CARD(dexofcard);

//showcard(dexofcard,allcard);

    for (i=0;i<allcard;++i){
        if (dexofcard[i]%100 < 29){
            table_card[0] = dexofcard[i];

            for (;i<allcard;++i){
                dexofcard[i] = dexofcard[i+1];
            }

            dexofcard[allcard] = 0;
            --allcard;
            ++i;
        }
    }

    for (i=0;i<card_p1;++i){
        p1_card[i] = dexofcard[0];
        runcard(dexofcard,allcard);
        p2_card[i] = dexofcard[0];
        runcard(dexofcard,allcard);
    }



    start();


    for (round=1;card_p1 != 0 && card_p2 != 0;++round){
        //system("CLS");

        if (stop==0){
            stop=1;
            p1();
            printf("---------------------- Turn %2d ----------------------",round);
            printf("\n\nTable card card is ");
            showcard(table_card,card_table);
            printf(" ....\n");
            printf("You can't play 1 turn!!");
        }
        if (stop==1){
            p1();
            printf("---------------------- Turn %2d ----------------------",round);

            printf("\n%d\n\n\n",card_p2);

            printf("Table card card is ");
            showcard(table_card,card_table);
            printf(" ....\n");

            printf("\n        You have %d card(s)\n\n",card_p1);
            showcard(p1_card,card_p1);


/////////////////////////////////////////////////



            for (i=0,check=0;i<card_p1;++i){
                if (p1_card[i]%100 == table_card[0]%100 || p1_card[i]/100 == table_card[0]/100 || p1_card[i] == 999 || p1_card[i] == 9999){
                    ++check;
                }
            }

            if (check==0){
                printf("\n......You no card!!!!\n");
                ++card_p1;
                p1_card[card_p1-1] = dexofcard[0];
                runcard(dexofcard,allcard);
                getch();
            }


            else{
                printf("\nWhat number of card do you put it! : ");
                scanf("%d",&ans);

                while (p1_card[ans-1]%100 != table_card[0]%100 && p1_card[ans-1]/100 != table_card[0]/100 && p1_card[ans-1] != 999 && p1_card[ans-1] != 9999){
                    printf("\n  Put again... :");
                    scanf("%d",&ans);
                }

                table_card[0] = p1_card[ans-1];

                if (p1_card[ans-1]%100 == 29 && p1_card[ans-1]%100 == 30){
                    stop=0;
                }

                if (p1_card[ans-1]%100 == 33 && p1_card[ans-1]%100 == 33){
                    for (i=0;i<2;++i){
                        ++card_p2;
                        p2_card[card_p2-1] = dexofcard[0];
                        runcard(dexofcard,allcard);
                    }
                }

                if (p1_card[ans-1] == 999){
                    printf("\nChose the color (1.Green  2.Blue  3.Red  4.Yellow)\n\t\tYou chose number ...");
                    scanf("%d",&i);

                    while (i<1 || i>4){
                        scanf("%d",&i);
                    }
                    switch (i){
                        case 1:
                            table_card[0] = 100;
                            break;
                        case 2:
                            table_card[0] = 200;
                            break;
                        case 3:
                            table_card[0] = 300;
                            break;
                        case 4:
                            table_card[0] = 400;
                            break;
                    }
                }

                if (p1_card[ans-1] == 9999){
                    for (i=0;i<4;++i){
                        ++card_p2;
                        p2_card[card_p2-1] = dexofcard[0];
                        runcard(dexofcard,allcard);
                    }

                    printf("Chose the color (1.Green  2.Blue  3.Red  4.Yellow)\n\t\tYou chose number ...");
                    scanf("%d",&i);

                    while (i<1 || i>4){
                        scanf("%d",&i);
                    }
                    switch (i){
                        case 1:
                            table_card[0] = 100;
                            break;
                        case 2:
                            table_card[0] = 200;
                            break;
                        case 3:
                            table_card[0] = 300;
                            break;
                        case 4:
                            table_card[0] = 400;
                            break;
                    }
                }

                for (;ans<card_p1;++ans){
                    p1_card[ans-1] = p1_card[ans];
                }

                --card_p1;
            }
        }


//////////////////////////////////////////////////


        if (stop==0){
            stop=1;
            p2();
            printf("---------------------- Turn %2d ----------------------",round);
            printf("\n\nTable card card is ");
            showcard(table_card,card_table);
            printf(" ....\n");
            printf("You can't play 1 turn!!");
        }
        if (stop==1) {
            p2();
            printf("---------------------- Turn %2d ----------------------",round);

            printf("\n%d\n\n\n",card_p1);

            printf("Table card card is ");
            showcard(table_card,card_table);
            printf(" ....\n");


            printf("\n        You have %d card(s)\n\n",card_p2);
                showcard(p2_card,card_p2);






/////////////////////////////////////////////////



            for (i=0,check=0;i<card_p1;++i){
                if (p2_card[i]%100 == table_card[0]%100 || p2_card[i]/100 == table_card[0]/100 || p2_card[i] == 999 || p2_card[i] == 9999){
                    ++check;
                }
            }

            if (check==0){
                printf("\n......You no card!!!!\n");
                ++card_p2;
                p2_card[card_p2-1] = dexofcard[0];
                runcard(dexofcard,allcard);
                getch();
            }


            else{
                printf("\nWhat number of card do you put it! : ");
                scanf("%d",&ans);

                while (p2_card[ans-1]%100 != table_card[0]%100 && p2_card[ans-1]/100 != table_card[0]/100 && p2_card[ans-1] != 999 && p2_card[ans-1] != 9999){
                    printf("\n    Put again... :");
                    scanf("%d",&ans);
                }

                table_card[0] = p2_card[ans-1];

                if (p2_card[ans-1]%100 == 33 && p2_card[ans-1]%100 == 33){
                    for (i=0;i<2;++i){
                        ++card_p1;
                        p1_card[card_p1-1] = dexofcard[0];
                        runcard(dexofcard,allcard);
                    }
                }

                if (p2_card[ans-1]%100 == 29 && p2_card[ans-1]%100 == 30){
                    stop=0;
                }

                if (p2_card[ans-1] == 999){
                    printf("Chose the color (1.Green  2.Blue  3.Red  4.Yellow)\n\t\tYou chose number ...");
                    scanf("%d",&i);

                    while (i<1 || i>4){
                        scanf("%d",&i);
                    }
                    switch (i){
                        case 1:
                            table_card[0] = 100;
                            break;
                        case 2:
                            table_card[0] = 200;
                            break;
                        case 3:
                            table_card[0] = 300;
                            break;
                        case 4:
                            table_card[0] = 400;
                            break;
                    }
                }

                if (p1_card[ans-1] == 9999){
                    for (i=0;i<4;++i){
                        ++card_p1;
                        p1_card[card_p1-1] = dexofcard[0];
                        runcard(dexofcard,allcard);
                    }
                        printf("Chose the color (1.Green  2.Blue  3.Red  4.Yellow)\n\t\tYou chose number ...");
                        scanf("%d",&i);

                        while (i<1 || i>4){
                            scanf("%d",&i);
                        }
                        switch (i){
                            case 1:
                                table_card[0] = 100;
                                break;
                            case 2:
                                table_card[0] = 200;
                                break;
                            case 3:
                                table_card[0] = 300;
                                break;
                            case 4:
                                table_card[0] = 400;
                                break;
                        }
                }

                for (;ans<card_p2-1;++ans){
                    p2_card[ans-1] = p2_card[ans];
                }

                --card_p2;
            }
        }
        //getch();
    }
/////GAME END
    if (card_p1 == 0){
        system("CLS");
        printf("\n            P1 Win !!\n");
    }
    else {
        system("CLS");
        printf("\n            P2 Win...\n");
    }

    return 0;
}