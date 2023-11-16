#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


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

unsigned long long sieveBound(unsigned num)
{
    assert(num > 20);
    double dnum = num;
    double dres = dnum * (log(dnum) + log(log(dnum)));
    return (unsigned long long) round(dres);
}

int isPrime(Array *sieve, int num)
{
    return (sieve->arr[num] == '1') ? 0 : 1;
}

int main()
{
    unsigned n;
    scanf("%d", &n);

    int num = sieveBound(n);
    char* arr = (char*) calloc(num, sizeof(char));
    if (!arr) return 1;

    Array sieveArr = {arr, num};

    fillSieve(&sieveArr);

    printSieve(&sieveArr);
    printf("\nResult: %d", isPrime(&sieveArr, n));
    free(arr);
    printf("\n");
    return 0;
}

