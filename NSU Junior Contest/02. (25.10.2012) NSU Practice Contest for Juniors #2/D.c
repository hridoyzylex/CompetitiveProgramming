#include <stdio.h>
#include <string.h>

int main()
{
    freopen("D.txt", "r", stdin);
    int i,j,k,t,pos;
    int K,N,marks,gap;
    int a[50];

    scanf("%d", &K);
    for (i=0; i<K; i++)
    {
        gap = 0;
        scanf("%d", &N);
        for (j=0; j<N; j++)
        {
            scanf("%d", &marks);
            a[j] = marks;
        }

        for (j=0; j<N; j++)
        {
        pos=j;
            for (k=j; k<N; k++)
            {
                if (a[k]<a[pos])
                    pos = k;
            }
        t=a[j];
        a[j]=a[pos];
        a[pos]=t;
        }

        for (j=0; j<N-1; j++)
        {
            if ((a[j+1]-a[j])>gap)
                gap = (a[j+1]-a[j]);

        }

    printf("Class %d\n", i+1);
    printf("Max %d, Min %d, Largest gap %d\n", a[N-1], a[0], gap);
    }

    return 0;
}
