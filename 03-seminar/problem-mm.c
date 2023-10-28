#include <assert.h>
#include <stdio.h>


// Find min and max in array
void findMinMax(int* arr, int len)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Min: %d, Max: %d \n", min, max);
}


int main()
{
    int len = 10;
    int arr[10] = {23, 45, 78, 33, 11, 7, 89, 12, 34, 66};
    findMinMax(arr, len);
    return 0;
}
