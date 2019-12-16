#include<stdio.h>
int main()
{
    int m,n,t;

    scanf("%d",&m);
    for(t=0; t<m; t++)
    {
        scanf("%d",&n);
        if(n>0 && n<=10)
        {
            printf("%d %d\n",0, n);
        }
        else if(n>10 && n<=20)
        {
            printf("%d %d\n",10,n-10);

        }
    }
    return 0;

}
