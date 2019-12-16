#include <stdio.h>
#include <math.h>

#define pi 2*acos(0.0)

int main()
{
    int T,i;
    double r;
    scanf("%d", &T);

    for (i=0; i<T; i++)
    {
        scanf("%lf", &r);
        printf("Case %d: %0.2lf\n", i+1, ((2*r)*(2*r))-pi*(r*r));

    }
    return 0;
}
