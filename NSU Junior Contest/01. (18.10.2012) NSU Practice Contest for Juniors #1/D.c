#include <stdio.h>
#include <string.h>
#include <string.h>

int main()
{
    int i;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;

    char a[100];
    gets(a);

    for (i=0; a[i]!='\0'; i++)          //case1
    {
        if((a[i] >= 'A')&&(a[i] <= 'Z'))
            flag1 = 0;
        else
        {
            flag1 = 1;
            break;
        }
    }
    if (flag1==0)
    {
        for (i=1; a[i]!='\0'; i++)
        {
            if((a[i] >= 'A')&&(a[i] <= 'Z'))
                a[i] = a[i] + ('a'-'A');
        }
        puts(a);
    }

    if((a[0] >= 'a')&&(a[0] <= 'z'))
        flag3 = 1;
    for (i=1; a[i]!='\0'; i++)          //case2
    {
        if((a[i] >= 'A')&&(a[i] <= 'Z'))
            flag2 = 0;
        else
        {
            flag2 = 1;
            break;
        }
    }
    if ((flag2==0)&&(flag3==1))
    {
        a[0] = a[0] - ('a'-'A');
        for (i=1; a[i]!='\0'; i++)
        {
            if((a[i] >= 'A')&&(a[i] <= 'Z'))
                a[i] = a[i] + ('a'-'A');
        }
        puts(a);
    }

    if ((flag1==1)&&(flag2==1))
        puts(a);

    return 0;
}
