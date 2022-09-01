#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    int X,Y;
};

float slop_cal(struct point point1, struct point point2);
float distance_cal(struct point point1, struct point point2);
void line_eq(float m, float c);

int main()
{
    struct point point1;
    struct point point2;
    float c;

    printf("Enter x1 : ");
    scanf("%d", &point1.X);
    printf("Enter y1 : ");
    scanf("%d", &point1.Y);
    printf("Enter x2 : ");
    scanf("%d", &point2.X);
    printf("Enter y2 : ");
    scanf("%d", &point2.Y);

    printf("\nReceived Coordinate : (%d,%d) and (%d,%d)", point1.X, point1.Y, point2.X, point2.Y);
    printf("\nDistance %.3f", distance_cal(point1, point2));
    printf("\nSlope : %.3f", slop_cal(point1, point2 ));
    c = (float)point1.Y - (slop_cal(point1, point2) * point1.X);
    line_eq(slop_cal(point1, point2),c);

    return 0;
}


float slop_cal(struct point point1, struct point point2) {
    return (float)(point2.Y-point1.Y)/(point2.X-point1.X);
}

float distance_cal(struct point point1, struct point point2) {
    return (float)pow((pow((point2.X - point1.X),2.0)+ pow((point2.Y-point1.Y),2.0)),(1/2.0));
}

void line_eq(float m, float c) {
    printf("\nLine equation : y = %.2fx + %.2f", m, c);
}