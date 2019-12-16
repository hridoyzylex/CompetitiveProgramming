#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("I.txt", "r", stdin);
    int i,j,T,N,A,D;
    int cookies;

    cin>>T;
    for (i=0; i<T; i++)
    {
        cin>>N>>A>>D;
        cookies = A;
        for(j=0; j<N-1; j++)
        {
            A = A + D;
            cookies = cookies + A;
        }
    cout<<cookies <<endl;
    }
    return 0;
}
