#include<stdio.h>
int main()
{
    int i, j, k;
    for (i=0; i>=0; i++)
    {
        for (j=1; j<=50; j++)
        {
            for (k=0; k<j; k++)
            {
                printf(".");
            }
        printf("\n");
        }

        for (j=49; j>0; j--)
        {
            for (k=0; k<j; k++)
            {
                printf(".");
            }
        printf("\n");
        }
    }
    return 0;
}
