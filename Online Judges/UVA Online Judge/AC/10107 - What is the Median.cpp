#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    long long i=0, n;
    long long a[10005];

    while(cin>>n)
    {
        a[i] = n;
        i++;
        sort(a, a+i);

        if(i%2==0)
        {
            cout<<(a[i/2]+a[i/2-1])/2 <<endl;
        }
        else
        {
            cout<<a[i/2] <<endl;
        }
    }
    return 0;
}
