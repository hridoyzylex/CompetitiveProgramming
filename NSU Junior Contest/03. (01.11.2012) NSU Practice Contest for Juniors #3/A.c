#include <stdio.h>

int main()
{
    freopen("A.txt", "r", stdin);
    int i;
    double amount, sum = 0.0;

    for (i=0; i<12; i++)
    {
        scanf("%lf", &amount);
        sum = sum + amount;
    }

    printf("$%0.2lf\n", sum/12);
    return 0;
}
