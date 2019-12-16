#include <stdio.h>

int main()
{
    freopen("D.txt", "r", stdin);
    int T;
    long long i, j, a, b, sum;

    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        sum = 0;

        scanf("%lld %lld", &a, &b);
        for(j=a; j<=b; j++)
        {
            sum = sum + j*j;

            if (a==b)
                break;
        }
    printf("Case %lld: %lld\n", i+1, sum);
    }
    return 0;
}
