#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


typedef struct Array
{
    char* arr;
    unsigned long long length;
} Array;

void printSieve(Array* sieveArr)
{
    for (unsigned long long i = 2; i < sieveArr->length; ++i)
    {
        if (sieveArr->arr[i] == '\0')
        {
            printf("%lld, ", i);
        }
    }
}

void fillSieve(Array* sieveArr)
{
    for (unsigned long long i = 2; i < sieveArr->length; ++i)
    {
        if (sieveArr->arr[i] == '1')
        {
            continue;
        }
        for (unsigned long long k = i * i; k < sieveArr->length; k = k + i)
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

int isPrime(Array *sieve, long long num)
{
    return (sieve->arr[num] == '1') ? 0 : 1;
}

int calculateExpression(long long n, long long a, long long b)
{
    return (n * n + a * n + b);
}

int getMaxPrimeNumbers(long long a, long long b, Array* sieve, long long nMax)
{
    for (long long i = 0; i < nMax; ++i)
    {
        if (!isPrime(sieve, calculateExpression(i, a, b)))
        {
           return i - 1; 
        }
    }
    return 0;
}

int main()
{ 
    long long maxN;
    scanf("%lld", &maxN);
    int maxA = 1000;
    int maxB = 1000;
    long long num = calculateExpression(maxN, maxA, maxB);
    char* arr = (char*) calloc(num, sizeof(char));
    if (!arr) return 1;
    Array sieveArr = {arr, num};
    fillSieve(&sieveArr);
    /* printSieve(&sieveArr); */
    long long maxPrimeNumbers = 0;
    long long aExpression = 0;
    long long bExpression = 0;

    for (long long a = 0; a < maxA; ++a)
    {
        for (long long b = 0; b < maxB; ++b)
        {
           long long currentPrimeNumbers = getMaxPrimeNumbers(a, b, &sieveArr, maxN); 
           if (currentPrimeNumbers > maxPrimeNumbers)
           {
               aExpression = a;
               bExpression = b;
               maxPrimeNumbers = currentPrimeNumbers;
           }
        }
    }

    printf("Formula: n*n + %lld * n + %lld, maxPrimeNumbers: %lld", aExpression, bExpression, maxPrimeNumbers);
    free(arr);
    printf("\n");
    return 0;
}

