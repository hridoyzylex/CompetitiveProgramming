#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long i, T,n,d,num, sum, var;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n>>d;

        sum = 1;
        num = d;

        while(1)
        {
            if (num < n)
            {
                num=num*10 + d;
                sum = sum + 1;
            }

            var = num % n;

            if( var == 0)
                break;
            else
                num=var;
        }
        cout<<"Case " <<i+1 <<": " <<sum <<endl;
    }
    return 0;
}
