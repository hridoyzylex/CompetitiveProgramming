#include<stdio.h>
int main()
{
    int a=0,b=1,c=0,i,d;


    printf("Enter number till u wanna c fib no :");
    scanf("%d",&d);
    i=0;

    while(i!=d)
    {
    c=a+b;
    a=b;
    b=c;
    i++;
    printf("%d fib is %d\n", i, c);
    }

    return 0;
}
