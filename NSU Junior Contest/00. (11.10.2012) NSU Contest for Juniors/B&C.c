#include <stdio.h>

int main()
{
    freopen("B&C.txt", "r", stdin);
    int T, i, j, k, N, num, counter, temp;

    scanf("%d", &T);
    for(i=0; i<T; i++)
    {

        printf("Case %d:\n", i+1);

        scanf("%d", &N);
        int a[N];
        for (j=0; j<N; j++)
        {
            counter = 0;
            scanf("%d", &a[j]);
            for(k=0; k<j; k++)
            {
                if (a[k]<=a[j])
                    counter++;
            }
            printf("%d\n", counter);
        }
    }
    return 0;
}
