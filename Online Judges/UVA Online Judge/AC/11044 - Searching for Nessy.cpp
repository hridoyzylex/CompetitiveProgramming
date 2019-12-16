#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int i,t,n,m;

    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n>>m;
        cout<<(n/3)*(m/3)<<endl;
    }
}
