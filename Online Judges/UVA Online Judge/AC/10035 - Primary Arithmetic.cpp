#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("Input.txt", "r", stdin);

    long int a,b;
    int count,c;

    scanf("%lu %lu",&a,&b);
    while(a!=0 || b!=0)
    {
        count=c=0;
        while(a||b)
        {
            c=(a%10+b%10+c)/10;
            a=a/10;
            b=b/10;
            count=count+c;
        }
        if(count==0)
            printf("No carry operation.\n");
        else if(count==1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n",count);

        scanf("%lu %lu",&a,&b);
    }
    return 0;
}
