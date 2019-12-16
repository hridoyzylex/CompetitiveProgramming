#include <stdio.h>
int main()
{
    long long T,i,j;
    long long W;

    scanf("%lld", &T);
    for (i=0; i<T; i++)
    {
        scanf("%lld", &W);
        if (W%2!=0)
            printf("Case %d: Impossible\n", i+1);
        else
        {
            for (j=2; j<=W; j=j+2)
            {
                if ((W%j==0)&&((W/j)%2!=0)){
                    printf("Case %lld: %lld %lld\n", i+1, W/j, j);
                    break;
                }
            }
        }

    }
    return 0;
}
