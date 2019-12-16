#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,hours=0;

    cin>>a>>b;
    hours = a;
    while(a/b>=1)
    {
        hours = hours + a/b;
        a = a/b;
    }
    cout<<hours;
    return 0;
}
