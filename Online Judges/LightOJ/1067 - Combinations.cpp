#include <iostream>
#include <stdio.h>
using namespace std;

long long fac(long long x)
{
    long long j;
    long long factorial = 1;

    for(j=1; j<=x; j++)
    {
        factorial = factorial*j;
    }

    return factorial;
}

int main()
{
    freopen("input.txt", "r", stdin);
    long long i,T,n,k;
    long long combination;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n>>k;

        combination = fac(n) / ( (fac(k))*(fac(n-k)) );
        //cout<<fac(10)<<endl;
        //cout<<fac(1)<<endl;
        //cout<<fac(100-1)<<endl;

        cout<<"Case " <<i+1 <<": " <<combination <<endl;
    }
}
