#include <stdio.h>

int main()
{
    int i,j;
    int counter = 1;
    long long num, sum;

    scanf("%lld", &num);
    for (i=1; i<=num/2; i++)
    {
        sum = 0;
        for (j=i; sum<=num; j++)
        {
            sum = sum + j;
            if (sum==num)
                counter++;
        }
    }
    printf("%d", counter);

    return 0;
}
