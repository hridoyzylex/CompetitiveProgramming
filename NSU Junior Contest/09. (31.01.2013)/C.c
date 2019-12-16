#include<stdio.h>

int main()
{
    freopen ("C.txt", "r", stdin);
    long long a,b,c,d,e,m, temp, sum, i, j, T;

    scanf("%lld", &T);
    for (i=0; i<T; i++)
    {
        sum = 0;
        scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &m);

        for (j=0; sum<m; j++)
        {
            sum = a+b+c+d+e;
            temp = a;
            a = a + b;
            b = b + c;
            c = c + d;
            d = d + e;
            e = e + temp;

            //printf("%d %d %d %d %d\n", a, b, c, d, e);
            if((sum<=0)&&(m>0))
            {
                j=0;
                break;
            }
        }
        printf("Case #%lld: %lld\n", i+1, j-1);
    }
    return 0;
}
