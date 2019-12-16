#include <stdio.h>
#include <string.h>

    int T,i,j,k, flag;
    char n[]="";
    char dummy[5];
int main()
{
    scanf("%d", &T);

    for (k=0; k<T; k++)
    {
    flag = 1;
    gets(dummy);
    scanf("%s", n);

    i = strlen(n);
    for (j=0; j<=(i/2); j++, i--)
    {
        if (n[j] != n[i-1])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        printf("Case %d: Yes\n", k+1);
    else
        printf("Case %d: No\n", k+1);
    }
    return 0;
}
