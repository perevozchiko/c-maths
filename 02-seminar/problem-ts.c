#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point 
{
    int x;
    int y;
} Point;

typedef struct Triangle 
{
    Point points[3];
} Triangle;

int abs(int value)
{
    if (value < 0) return -value;
    return value;
}

int doubleTriangleSquare(Triangle* triangle)
{
    Point point1 = triangle->points[0];
    Point point2 = triangle->points[1];
    Point point3 = triangle->points[2];
    return abs(point1.x * (point2.y - point3.y) + 
            point2.x * (point3.y - point1.y) + 
            point3.x * (point1.y - point2.y));
}


int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    Triangle triangle;
    triangle.points[0] = (Point){x1, y1};
    triangle.points[1] = (Point){x2, y2};
    triangle.points[2] = (Point){x3, y3};
    for (int i = 0; i < 3; i++)
    {
        printf("x: %d, y: %d\n", triangle.points[i].x, triangle.points[i].y);
    }
    printf("Square = %d\n", doubleTriangleSquare(&triangle));
}
