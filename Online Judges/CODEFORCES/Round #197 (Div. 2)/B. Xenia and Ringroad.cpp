#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    long long i;
    long long n,m,a, time=0, myPos=1;

    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>a;

        if(a>myPos)
        {
            time = time + (a-myPos);
            myPos = a;
        }

        if(a<myPos)
        {
            time = time + (n-myPos) + 1;
            myPos = 1;

            if(a>myPos)
            {
                time = time + (a-myPos);
                myPos = a;
            }
        }
    }

    cout<<time<<endl;

    return 0;
}
