#include <stdio.h>
#include <string.h>

int main()
{
    freopen("B.txt", "r", stdin);
    int i,j,k, l;
    int P, N, R;

    scanf("%d", &P);
    for(i=0; i<P; i++)
    {
        char S[25] = {0};
        char T[200] = {0};

        scanf("%d %d ", &N, &R);
        gets(S);

        for (j=0, k=0; S[j]!='\0'; j++)
        {
            for (l=0; l<R; l++, k++)
            {
                T[k] = S[j];
            }
        }
        printf("%d ", N);
        puts(T);
    }
    return 0;
}
