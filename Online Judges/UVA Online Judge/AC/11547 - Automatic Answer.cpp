#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int i,t,n;

    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n;

        n = n*567;
        n = n/9;
        n = n+7492;
        n = n*235;
        n = n/47;
        n = n - 498;

        n = n%100;
        n = n/10;

        if(n<0)
            cout<<-n <<endl;
        else
            cout<<n <<endl;
    }
    return 0;
}
