#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int i, n, no_k=0;
    long long fact=1;;
    char k[25];

    cin>>n>>k;

    for(i=0; i<25; i++)
    {
        if(k[i]=='!')
            no_k++;
    }

    fact = n;

    for(i=0; (n-no_k)>0;i++)
    {
        fact = fact*(n-no_k);
        n = n-no_k;
    }

    cout<<fact<<endl;

    return 0;
}
