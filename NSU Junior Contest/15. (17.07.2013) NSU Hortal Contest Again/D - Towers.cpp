#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int i,N,l,largest=1, counter=0;
    int a[1005];

    for(i=0; i<1005; i++)
        a[i] = 0;

    cin>>N;
    for(i=0; i<N; i++)
    {
        cin>>l;
        a[l] = a[l]+1;
    }

    for(i=0; i<1001; i++)
    {
        if(a[i]>largest)
            largest = a[i];

        if(a[i] != 0)
            counter++;
    }

    cout<<largest <<" " <<counter <<endl;

    return 0;
}
