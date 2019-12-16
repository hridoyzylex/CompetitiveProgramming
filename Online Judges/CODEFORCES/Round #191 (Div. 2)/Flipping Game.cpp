#include <iostream>
using namespace std;

int main()
{
    int i,j,k;
    int n,digit, ones = 0, zeros = 0;
    int a[100];

    for(i=0; i<100; i++)    //initialize with a value other than 0 and 1;
    {
        a[i] = 2;
    }

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>digit;
        a[i] = digit;
    }

    for(i=0; a[i]!=0; i++)
    {
        if(a[i]==1)
            ones++;
    }

    for(j=n; a[j]!=0; j--)
    {
        if(a[j]==1)
            ones++;
    }

    //cout<<i <<" " <<j <<endl;

    for(k=i; k<=j; k++)
    {
        if(a[k]==0)
            ones++;
    }

    cout<<ones <<endl;

    return 0;
}
