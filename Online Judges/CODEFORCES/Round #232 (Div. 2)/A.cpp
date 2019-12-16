#include <iostream>
using namespace std;

int main()
{
    int arr[105];
    int i, j, n,l,r, l_my, r_my, sum=0;

    for(i=0; i<=100; i++)
        arr[i] = 0;

    cin>>n;
    cin>>l_my>>r_my;
    for(i=0; i<n-1; i++)
    {
        cin>>l>>r;
        for(j=l; j<r; j++)
            arr[j] = 1;
    }

    for(i=l_my; i<r_my; i++)
    {
        if(arr[i]==0)
            sum++;
    }
    cout<<sum;
    return 0;
}
