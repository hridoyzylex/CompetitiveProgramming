#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("J.txt", "r", stdin);

    int i,j,N,event,counter;

    cin>>N;
    for (i=0; N!=0; i++)
    {
        counter = 0;
        for (j=0; j<N; j++)
        {
            cin>>event;
            if (event==0)
                counter++;
        }

    cout<<"Case " <<i+1 <<": " <<(N-counter)-counter <<endl;

    cin>>N;
    }
    return 0;
}
