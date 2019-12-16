#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i,j,n, number=2, ones=0, zeros=0;

    cin>>n;
    for(i=0; number!=0; i++)
    {
        cin>>number;

        if(number==1)
            ones++;

    }

    if(number==0)
    {
        for(j=0; j<n-i; j++)
        {
            cin>>number;

            if(number==0)
                ones++;
        }
    }

    cout<<ones <<endl;

    return 0;
}
