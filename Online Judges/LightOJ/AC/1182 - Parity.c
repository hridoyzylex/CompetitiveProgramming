#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, n, T, counter;
    char s[32];

    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        counter = 0;
        scanf("%d", &n);

        for (j=0; n!=0; j++)
        {
            s[j] = n%2;// + '0';
            n = n/2;

            if (s[j] == 1)
                counter = (counter + 1);
        }

        if (counter%2==0)
            printf("Case %d: even\n", i+1);
        else
            printf("Case %d: odd\n", i+1);
    }
    return 0;
}

