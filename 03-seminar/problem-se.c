#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>


unsigned linear_search(int const *parr, unsigned len, int elem)
{
    for (int i = 0; i < len; ++i)
    {
        if (parr[i] == elem)
        {
            return i;
        }
    }
    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selsort(int *arr, unsigned len)
{
    for (int i = 0; i < len; ++i)
    {
        
    }
}

int main()
{
    const int LEN = 6;
    int arr[LEN] = {3,1,9,2,4,7};
    selsort(arr, LEN);

    for (int i = 0; i < LEN; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}
