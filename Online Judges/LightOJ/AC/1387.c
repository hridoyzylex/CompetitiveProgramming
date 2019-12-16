#include <stdio.h>
#include <string.h>

int main()
{
    int T, S, i, j;
    long long sum, total;
    char word[10]="";
    char don[] = "donate";
    char rep[] = "report";
    char bin[2] = "";

    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        total = 0;
        printf("Case %d:\n", i+1);

        scanf("%d", &S);
        for (j=0; j<S; j++)
        {
            gets(bin);
            scanf("%s", &word);

            if (strcmp(word, don)==0)
            {
                scanf("%lld", &sum);
                total = total + sum;
            }

            else if (strcmp(word, rep)==0)
            {
                printf("%lld\n", total);
            }
        }
    }
    return 0;
}
