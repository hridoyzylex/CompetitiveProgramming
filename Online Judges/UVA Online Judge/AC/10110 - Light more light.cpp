#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()                          //if the number is a perfect square then "yes" else "no".
{
    freopen("Input.txt", "r", stdin);
    long long n,a,b;

    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;

        a=sqrt(n);
        b=a*a;

        if(b==n)
            printf("yes\n");
        else
            printf("no\n");
    }

    return(0);
}
