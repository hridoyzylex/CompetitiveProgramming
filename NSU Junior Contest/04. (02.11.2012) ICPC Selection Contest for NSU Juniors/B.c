#include <stdio.h>

int main()
{
    freopen ("B.txt", "r", stdin);
    int i,j,t,counter=0;
    int N, D;
    int a[30000];

    scanf("%d", &N);
    for (i=0; i<N; i++)
    {
        scanf("%d", &D);
        a[i] = D;
    }
    for (i=0; i<N-1; i++)
    {
        if (a[i]>a[i+1])
        {
            for (j=N-1; j>i; j--)
            {
                if (a[j]==1)
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                    counter = counter + 2;
                    break;
                }
            }
        }

    }
    printf("%d", counter);
    return 0;
}
