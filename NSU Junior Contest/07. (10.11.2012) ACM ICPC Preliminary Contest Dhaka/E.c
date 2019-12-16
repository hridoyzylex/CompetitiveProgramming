#include <stdio.h>

int main()
{
    int i, T;
    long long x1, y1, x2, y2, xmid, ymid, gradient;

    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        xmid = (x1 + x2)/2;
        ymid = (y1 + y2)/2;

        if ( x1 != x2){
            gradient = (y2-y1)/(x2-x1);

            if (gradient > 0)
                printf("Case %d: %lld %lld %lld %lld\n", i+1, xmid-1, ymid+1, xmid+1, ymid-1);

            else if (gradient < 0)
                printf("Case %d: %lld %lld %lld %lld\n", i+1, xmid-1, ymid-1, xmid+1, ymid+1);

            else if (gradient == 0)
                printf("Case %d: %lld %lld %lld %lld\n", i+1, xmid, ymid+1, xmid, ymid-1);
        }

        else
            printf("Case %d: %lld %lld %lld %lld\n", i+1, x1-1, y1, x1+1, y1);



    }


    return 0;
}
