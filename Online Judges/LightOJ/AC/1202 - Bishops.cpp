#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);

    int i, T;
    long long r1,c1,r2,c2;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>r1>>c1>>r2>>c2;

        if(r1+c2==r2+c1 || fabs(r1-r2)==fabs(c1-c2))
            cout<<"Case " <<i+1 <<": 1" <<endl;

        else if(r1+c2==fabs(r2-c1) || fabs(r1-c2)==r2+c1||(r1+r2)%2==(c1+c2)%2)
            cout<<"Case " <<i+1 <<": 2" <<endl;

        else
            cout<<"Case " <<i+1 <<": impossible" <<endl;
    }
    return 0;
}
