#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
    char a[206];
    int i,j,k,n,T;
    long p;
    long long sum;

    cin>>T;
    for(j=0; j<T; j++)
    {
        cin>>a>>p;
        if(p<0)
            p=-p;

        n=strlen(a);

        sum=0;

        for(i=0; i<n; i++)
        {
            if(a[i]=='-') continue;

            sum=sum+(a[i]-'0');

            if(sum>=p)
                sum=sum%p;
            if(i!=n-1&&sum<p)
                sum=sum*10;
            else if(i==n-1&&sum>p)
                sum=sum%p;
        }

        if(sum==0)
            cout<<"Case " <<j+1 <<": divisible" <<endl;
        else
            cout<<"Case " <<j+1 <<": not divisible" <<endl;
    }
    return 0;
}
