#include <stdio.h>
#include <iostream>
using namespace  std;

int main()
{
    freopen("E.txt", "r", stdin);

    int i,T,N,A,D,total;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>N>>A>>D;

        total = (N*A) + D*((N-1)*N)/2;

        cout<<total <<endl;
    }
    return 0;
}
