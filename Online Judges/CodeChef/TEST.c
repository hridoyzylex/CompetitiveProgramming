#include<stdio.h>

int main()
{
    int i,n;

    while(1)
    {
        scanf("%d", &n);

        if(n==42)
            break;
        else
            printf("%d\n", n);
    }

    return 0;
}
