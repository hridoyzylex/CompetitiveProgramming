#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int i,a,b,counterA=0, counterB=0, counterEq=0;

    cin>>a>>b;

    for(i=1; i<=6; i++)
    {
        if(fabs(a-i)<fabs(b-i))
            counterA++;
        if(fabs(b-i)<fabs(a-i))
            counterB++;
        if(fabs(a-i)==fabs(b-i))
            counterEq++;
    }
    cout<<counterA <<" " <<counterEq <<" "<<counterB;

    return 0;
}
