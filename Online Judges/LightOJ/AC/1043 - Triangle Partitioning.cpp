#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int i, T;
    double div,ab,ac,bc, AD,ratio;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>ab>>ac>>bc>>ratio;

        ratio = 1.0/ratio;

        div = sqrt(ratio+1);
        AD = (ab/div);

        printf("Case %d: %.10lf\n",i+1,AD);
    }
    return 0;
}
