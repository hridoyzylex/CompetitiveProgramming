#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int i,j,T,N,num, lies;
    int arr[15];

    cin>>T;
    for(i=0; i<T; i++)
    {
        lies = 0;
        arr[0] = 2;

        cin>>N;
        for(j=0; j<N; j++)
        {
            cin>>arr[j+1];
        }

        for(j=0; j<N; j++)
        {
            if(arr[j+1]>arr[j])
            {
                lies = lies + ceil((double)(arr[j+1]-arr[j])/5);
            }
        }

        cout<<"Case " <<i+1 <<": " <<lies <<endl;
    }

    return 0;
}
