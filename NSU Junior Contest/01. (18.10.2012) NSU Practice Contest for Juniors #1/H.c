#include <stdio.h>

int main()
{
    int n, m, pos, i, j, t;
    int sum = 0;
    int counter = 0;

    scanf("%d %d", &n, &m);
    int a[n];

    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i=0; i<n; i++){
    pos=i;
        for (j=i; j<n; j=j+1){
            if (a[j]<a[pos])
                pos = j;
        }
        t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }
    for (i=0; i<m; i++)
    {
        if (a[i]<0)
        {
            sum = sum -(a[i]);
            counter++;
        }
        if (counter==m)
            break;
    }
    printf("%d", sum);
    return 0;
}
