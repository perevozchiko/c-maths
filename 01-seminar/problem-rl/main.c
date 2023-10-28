#include <assert.h>
#include <stdio.h>

int iabs(int x)
{
    return (x < 0) ? -x : x;
}

int eu_mod(int x, int y)
{
   int r;
    assert(y != 0);
    r = x % y;
    if (r < 0) r += iabs(y);
    return r;
}

int gcd(int x, int y)
{
    int q = eu_mod(x, y);
    int res = 0;
    while (q != 0)
    {
        res = q;
        q = eu_mod(y, q);
    }
    return res;
}

// find sum to num % first and second numbers
int summNumbers(int allNum, int first, int second)
{
    int summ = 0;
    for (int i = 0; i <= allNum; i++)
    {
       if (i % first == 0 || i % second == 0) 
       {
           summ += i;
       }
    }
    return summ;
}

int main()
{
    int x, y;
    printf("Input two number:");
    scanf("%d%d", &x, &y);
    int result = gcd(x, y);
    printf("Result: %d \n", result);
}
