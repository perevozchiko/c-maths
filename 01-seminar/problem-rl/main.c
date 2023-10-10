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
    return (q == 0) ? y : gcd(y, q);
}


int main()
{
    while(1)
    {
        int x, y;
        printf("Input two number:");
        scanf("%d%d", &x, &y);

        if (x == -1 || y == -1) break;
        int result = gcd(x, y);

        printf("Result: %d \n", result);

    }
    return 0;
}
