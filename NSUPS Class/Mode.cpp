#include<iostream>
using namespace std;

int main()
{
    int i, max, mode, modeVal;
    int a[5] = {2,2,1,1,2};

    max = a[0];
    for(i=1; i<5; i++)
    {
        if(a[i]>max)
            max = a[i];
    }

    int b[max];

    for(i=0; i<5; i++)
        b[i] = 0;

    for(i=0; i<5; i++)
    {
        b[a[i]] = b[a[i]] + 1;
    }

    mode = b[0];
    modeVal = 0;

    for(i=1; i<5; i++)
    {
        if(b[i]>mode)
        {
            mode = b[i];
            modeVal = i;
        }
    }

    cout<<"Mode: " <<mode <<", Mode Value: " <<modeVal;

    return 0;
}

