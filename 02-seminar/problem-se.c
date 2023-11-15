#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Array
{
    char* arr;
    unsigned length;
} Array;

void printSieve(Array* sieveArr)
{
    for (unsigned i = 2; i < sieveArr->length; ++i)
    {
        if (sieveArr->arr[i] == '\0')
        {
            printf("%d, ", i);
        }
    }
}

void fillSieve(Array* sieveArr)
{
    for (unsigned i = 2; i < sieveArr->length; ++i)
    {
        if (sieveArr->arr[i] == '1')
        {
            continue;
        }
        for (unsigned k = i * i; k < sieveArr->length; k = k + i)
        {
            sieveArr->arr[k] = '1';
        }
    }
}

int main()
{
    unsigned n;
    scanf("%d", &n);
    char* arr = (char*) calloc(n, sizeof(char));
    if (!arr) return 1;

    Array sieveArr = {arr, n};

    fillSieve(&sieveArr);

    printSieve(&sieveArr);
    
    free(arr);
    printf("\n");
    return 0;
}
