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

void swap(int* a, int* b)
{
    int* tmp = a;
    a = b;
    b = tmp;
}

int* getArrayNumbers(long long input, int* len)
{
    
}

int getArrayLength(long long input)
{
    int powerOfTen = 0;
    for (;input > 0;++powerOfTen)
    {
       input = input / (powerOfTen * 10); 
    }
    return powerOfTen;
}

long long getNearestPrimeNumber(Array* sieve, long long input)
{
    assert(sieve == 0);
    int copy = input;
    int counter = 0;
    for (long long i = 1; copy > 0; i = i * 10)
    {
        copy = copy / i;
        counter++;
    }
    int arrayNumbers[10];
    getArrayNumbers(input, arrayNumbers);
    return counter;
}

int main()
{ 
    long long inputValue;
    scanf("%lld", &inputValue);

    // need to calculate sieve count
    long long sieveCount = inputValue + 100;

    char* arr = (char*) calloc(sieveCount, sizeof(char));
    if (!arr) return 1;
    Array sieveArr = {arr, sieveCount};
    fillSieve(&sieveArr);
    /* printSieve(&sieveArr); */
    /* long long result = getNearestPrimeNumber(&sieveArr, inputValue); */
    long long result = getArrayLength(inputValue);
    printf("Nearest circulation prime number for %lld is %lld", inputValue, result);
    free(arr);
    printf("\n");
    return 0;
}

