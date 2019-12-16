#include <stdio.h>

int main()
{
    int N, K, i;
    int a[50000][3] = {0};

    scanf("%d %d", &N, &K);
    for (i=0, j=1; i<N; i++, j++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
        a[i][2] = j;
    }
    for (i=0; i<N; i=i+1){
    pos=i;
        for (j=i; j<5; j=j+1){
            if (a[j]<a[pos])
                pos = j;
        }
        t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }

    return 0;
}
