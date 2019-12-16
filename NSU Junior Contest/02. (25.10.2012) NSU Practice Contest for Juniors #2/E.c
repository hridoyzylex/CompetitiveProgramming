#include <stdio.h>
#include <string.h>

int main()
{
    //freopen("E.txt", "r", stdin);
    int i,j,T,flag;
    char dummy[5];

    scanf("%d", &T);
    gets(dummy);
    for (i=0; i<T; i++)
    {
        flag = 0;
        char a[50] = {0};
        gets(a);

        for (j=0; j<=(strlen(a)); j++)
        {
            if (a[j]=='D')
            {
                flag = 1;
                break;
            }
        }
        if (flag==1)
            printf("You shall not pass!\n");
        else
            printf("Possible\n");
    }
    return 0;
}
