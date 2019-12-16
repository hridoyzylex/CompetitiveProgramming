#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

long double Fact(long double num)
{
    long double i, result=1;
    for(i=num ;i>0; i--)
    {
        result = result * i;
    }
    return result;
}
int main()
{
    freopen("Input.txt","r",stdin);
    long double n,m,c;
    while(cin>>n>>m && n!=0 && m!=0)
    {
        c = Fact(n)/(Fact(n-m)*Fact(m));

        cout<<n <<" things taken " <<m <<" at a time is " << fixed << setprecision(0) <<c <<" exactly." <<endl;
    }

    return 0;
}
