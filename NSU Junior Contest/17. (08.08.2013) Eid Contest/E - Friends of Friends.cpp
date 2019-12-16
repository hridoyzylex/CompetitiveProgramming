#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int i,j,k=0,x,N, total, counter = 0;
int a[10000];
int b[10000];

int main()
{
    freopen("E.txt", "r", stdin);

    cin>>N;
    for(i=0; i<N; i++)
    {
        cin>>a[i] >>x;
        counter = counter + x;
        for(j=0; j<x; j++)
        {
            cin>>b[k];
            k++;
        }
    }

    sort(b, b+counter);

    for(i=0; i<counter-1; )
    {
        if(b[i]==b[i+1])
        {
            b[i] = b[counter-1];
            counter--;
            sort(b, b+counter);
        }
        else
            i++;
    }

    total = counter;

    for(i=0; i<N; i++)
    {
        for(j=0; j<counter; j++)
        {
            if(a[i] == b[j])
            {
                total--;
                break;
            }
        }
    }
    cout<<total;

    return 0;
}
