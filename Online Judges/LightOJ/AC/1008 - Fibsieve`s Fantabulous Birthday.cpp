#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    long long i,n,T,x,y,sq,r;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n;
        long long sq=ceil(sqrt(n));
        long long r=sq*sq-n;

        if(r<sq)
        {
            y=r+1;
            x=sq;
        }
        else
        {
            x=2*sq-r-1;
            y=sq;
        }
        if( sq%2!=0)
            swap(x,y);

        cout<<"Case " <<i+1 <<": " <<x <<" " <<y <<endl;
    }
    return 0;
}
