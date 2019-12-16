#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n,i;
    char ch[50];
    int FirstHalf = 0;
    int SecondHalf = 0;
    char dummy[5];
    int flag = 0;

    scanf("%d", &n);
    gets(dummy);

    gets(ch);


    for (i=0; i<n; i++)
    {
        if ((ch[i]=='4')||(ch[i]=='7'))
            flag = 0;
        else
        {
            flag = 1;
            break;
        }
    }
    for (i=0; i<n/2; i++)
    {
        FirstHalf = FirstHalf + (ch[i] - '0');
    }
    for (i=n/2; i<n; i++)
    {
        SecondHalf = SecondHalf + (ch[i] - '0');
    }

    if ((flag==0)&&(FirstHalf==SecondHalf))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
