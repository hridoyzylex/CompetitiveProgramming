#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    freopen("C.txt", "r", stdin);
    int n, i;
    char a[100];
    char dummy[5];

    scanf("%d", &n);
    gets(dummy);
    for (i=0; i<n; i++)
    {
        gets(a);

        if (strlen(a)<=10)
            puts(a);

        else
        {
            printf("%c", a[0]);
            printf("%d", strlen(a)-2);
            printf("%c\n", a[strlen(a)-1]);
        }
    }
    return 0;
}
