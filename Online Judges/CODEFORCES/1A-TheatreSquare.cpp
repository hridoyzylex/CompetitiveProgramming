#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
using namespace std;

int main()
{
    unsigned long long n,m,a, flagstone;

    cin>>n>>m>>a;

    flagstone = ceil(1.0*n/a) * ceil(1.0*m/a);

    cout<<flagstone<<endl;

    return 0;
}
