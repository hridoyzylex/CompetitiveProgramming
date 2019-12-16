#include <stdio.h>

int main()
{
    int T, N, i, j;
    int dust, sum;

    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        sum = 0;
        scanf("%d", &N);
        for (j=0; j<N; j++)
        {
            scanf("%d", &dust);
            if (dust>=0)
                sum = sum + dust;
        }
        printf("Case %d: %d\n", i+1, sum);
    }
    return 0;
}
