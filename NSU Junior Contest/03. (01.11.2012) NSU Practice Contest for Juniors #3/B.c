#include <stdio.h>

int main()
{
    freopen("B.txt", "r", stdin);

    float length;
    float sum;
    int i, counter;

    scanf("%f", &length);
    while(length!=0.00)
    {
        sum =0.00;
        counter = 0;

        for (i=2; sum<=length; i++)
        {
            sum = sum + (1.0/i);
            counter++;
        }

    printf("%d card(s)\n", counter);
    scanf("%f", &length);
    }
    return 0;
}
