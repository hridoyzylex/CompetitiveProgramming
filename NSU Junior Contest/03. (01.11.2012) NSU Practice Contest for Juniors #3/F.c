#include <stdio.h>

int main()
{
    freopen("F.txt", "r", stdin);
    int i, N, a, b, sum, aRev, bRev, sumRev;

    scanf("%d", &N);
    for (i=0; i<N; i++)
    {
        scanf("%d %d", &a, &b);

        aRev=0;
        bRev=0;
        sumRev=0;

        while(a>0)
        {
            aRev *= 10;
            aRev += a%10;
            a /= 10;
        }

        while(b>0)
        {
            bRev *= 10;
            bRev += b%10;
            b /= 10;
        }

        sum = aRev + bRev;

        while(sum>0)
        {
            sumRev *= 10;
            sumRev += sum%10;
            sum /= 10;
        }
    printf("%d\n", sumRev);
    }
    return 0;
}
