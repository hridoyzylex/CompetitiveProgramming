#include <iostream>
#include <stdio.h>
#include <math.h>
#define PI (2*(acos(0.0)))
using namespace std;

int main ()
{
    freopen("input.txt", "r", stdin);
    int r1, r2, p, h, i ,T;
    double Vol, sHeight, r3;

    cin>>T;
    for (i=0; i<T; i++)
    {

        cin>>r1>>r2>>h>>p;
        sHeight = h /((1.0*r1/r2)-1);

        r3 = ((sHeight+p)/sHeight)*r2;

        Vol = ((1.0/3)*PI*r3*r3*(p+sHeight))-((1.0/3)*PI*r2*r2*sHeight); //Frustum

        printf("Case %d: %0.10lf\n", i+1, Vol);
    }
    return 0;
}
