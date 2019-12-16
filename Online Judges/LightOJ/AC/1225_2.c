#include <stdio.h>
int main()

{
    long long number, temp, remainder, sum;
    int i, T;

    scanf("%d", &T);

    for (i=0; i<T; i++)
    {
        sum = 0;
        scanf("%lld",&number);
        temp = number;

        while(number>0)
        {
            remainder=number%10;
            number/=10;
            sum=sum*10 + remainder;
        }

    if (sum==temp)
        printf ("Case %d: Yes\n", i+1);
    else
        printf ("Case %d: No\n", i+1);
    }
    return 0;
}
