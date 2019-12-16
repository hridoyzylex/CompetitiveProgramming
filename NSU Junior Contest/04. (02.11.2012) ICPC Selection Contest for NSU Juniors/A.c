#include <stdio.h>

int main()
{
    freopen ("A.txt", "r", stdin);
    int i,j;
    int N,S,L;
    int a[20000];
    int counter = 0;

    scanf("%d %d", &N, &S);

    for (i=0; i<N; i++)
    {
        scanf("%d", &L);
        a[i] = L;
    }
    for (i=0; i<N-1; i++)
    {
        if (a[i]==S)
            continue;
        else{
        for (j=i+1; j<N; j++)
        {
            if (a[i]+a[j]<=S)
                counter++;
        }
        }
    }
    printf("%d", counter);

    return 0;
}
