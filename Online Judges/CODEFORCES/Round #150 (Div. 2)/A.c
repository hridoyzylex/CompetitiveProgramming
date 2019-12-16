#include<stdio.h>

int main()
{
    int x, y, a, b, i;
    int flag = 0;

    scanf("%d", &x);
    scanf("%d", &y);

    for (i=0; i<x; i++)
    {
        scanf("%d %d", &a, &b);
        if ((y==a)||(y==b))
        {
            printf("NO");
            flag = 1;
            break;
        }
    }

    if (flag==0)
        printf("YES");



    return 0;
}
