#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>


unsigned moveright(int* arr, int key,  unsigned last)
{
    int i = last - 1;
    while (i >= 0 && arr[i] > key)
    {
        arr[i+1] = arr[i];
        --i;
    }
    return i+1;
}

void inssort(int* arr, unsigned len)
{
    for (unsigned i = 0; i < len; i++)
    {
        int key = arr[i];
        unsigned pos = moveright(arr, key, i);
        arr[pos] = key;
    }
}

int main()
{
    int arr[] = {3,6,4,8,1,9};
    inssort(arr, 6);

    for (unsigned i = 0; i < 6; ++i)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
    return 0;
}
