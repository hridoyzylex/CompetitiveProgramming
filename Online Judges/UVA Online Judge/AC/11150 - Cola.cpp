#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        n = n + n/2;
        cout<<n <<endl;
    }
    return 0;
}

