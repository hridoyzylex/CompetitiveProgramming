#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int i,j,k,n,num, sajera=0, dima=0, max=0;
    int a[1000];

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    j=0, k=n-1;
    for(i=0; i<n; i++)
    {
        if(a[j]>a[k])
        {
            max=a[j];
            j++;
        }
        else
        {
            max=a[k];
            k--;
        }

        if(i%2==0)
            sajera = sajera + max;
        else
            dima = dima + max;
    }

    cout<<sajera <<" " <<dima;
    return 0;
}
