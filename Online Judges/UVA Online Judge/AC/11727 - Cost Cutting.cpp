#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    int i,j,T;
    int a[3];

    cin>>T;
    for(i=0; i<T; i++)
    {
        for(j=0; j<3; j++)
        {
            cin>>a[j];
        }

        sort(a, a+3);
        cout<<"Case " <<i+1 <<": " <<a[1] <<endl;
    }

    return 0;
}
