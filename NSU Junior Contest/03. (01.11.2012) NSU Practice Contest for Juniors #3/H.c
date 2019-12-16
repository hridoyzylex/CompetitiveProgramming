#include<stdio.h>

int Sum_deci(int n);
int Sum_duodeci(int n);
int Sum_hexadeci(int n);

int main()
{
    int i;
    for(i=2992; i<=9999; i++)
    {
        if(Sum_deci(i)==Sum_duodeci(i) && Sum_duodeci(i)==Sum_hexadeci(i))
            printf("%d\n", i);
    }
    return 0;
}

int Sum_deci(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum = sum + n%10;
        n = n/10;
    }
    return sum;
}

int Sum_duodeci(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum = sum + n%12;
        n = n/12;
    }
    return sum;
}

int Sum_hexadeci(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum = sum + n%16;
        n = n/16;
    }
    return sum;
}

