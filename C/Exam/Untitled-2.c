#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct point{
    int x,y;
};

float slop_cal(struct point point1,struct point point2);
float distance_cal(struct point point1,struct point point2);
void line_eq(float m, float c);

int main(){
    struct point point1;
    struct point point2;
    float c,m,d;
    printf("Enter x1 : ");
    scanf("%d",&point1.x);
    printf("Enter y1 : ");
    scanf("%d",&point1.y);
    printf("Enter x2 : ");
    scanf("%d",&point2.x);
    printf("Enter y2 : ");
    scanf("%d",&point2.y);

    printf("\nReceived Coordinate : (%d,%d) and (%d,%d)",point1.x,point1.y,point2.x,point2.y);

    m = slop_cal(point1,point2);
    d = distance_cal(point1,point2);
    c = (float)point2.y-(m*point2.x);
    printf("\nDistance : %.3f",d);
    printf("\nSlope : %.3f",m);
    line_eq(m,c);
}

float slop_cal(struct point point1,struct point point2){
    return (float)(point2.y-point1.y)/(point2.x-point1.x);
}

float distance_cal(struct point point1,struct point point2){
    return (float)sqrt(pow((point2.x-point1.x),2)+pow((point2.y-point1.y),2));
}

void line_eq(float m, float c){
    printf("\nLine equation : y = %.2fx + %.2f\n",m,c);
}