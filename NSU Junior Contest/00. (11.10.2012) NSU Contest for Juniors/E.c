#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int T, N, S, i, j, k;
    int counter;

    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        char a[8] = {0};
        printf("Case %d:\n", i+1);
        counter = 0;

        scanf("%d %d", &N, &S);
        for (j=S+1; counter<=N; j++)
        {
            for (k=0; j!=0; k++)
            {
                a[i] = j%2 + '0';
                j = j/2;
            }
                a[i] = '\0';
                strrev(a);
                puts(a);
                counter++;
        }
    }
}
