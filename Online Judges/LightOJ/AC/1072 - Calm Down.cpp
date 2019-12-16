#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int  T,i,j;
    double x, r, n, res, pi=3.141592653589793;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>r>>n;

        x=(sin(pi/n));
        res=x*r/(1+x);

        //cout<<"Case " <<i+1 <<": " <<res <<endl;
        printf("Case %d: %lf\n",i+1,res);
    }
    return 0;
}
