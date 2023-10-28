#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

//  Fisher-Yates algorithm

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    const int len = 10;
    int arr[len] = {1,2,3,4,5,6,7,8,9,10};

    srand(time(NULL));
    
    for (int i = 0; i < len-1; i++)
    {
        int key = getRandomNumber(i+1, len-1);
        swap(&arr[i], &arr[key]);
    }

    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}
