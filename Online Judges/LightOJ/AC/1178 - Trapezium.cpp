#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int i,j,k,T;
    double a,b,c,d,s, height, triArea, trapArea;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>a>>b>>c>>d;
        s = (b+d+fabs(a-c))/2;
        triArea = sqrt(s*(s-b)*(s-d)*(s - fabs(a-c)));
        height = (triArea*2)/fabs(a-c);

        trapArea = 0.5*(a+c)*height;

        printf("Case %d: %.10lf\n",i+1, trapArea);
    }

    return 0;
}
