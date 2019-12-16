#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i,n,d,m,sum=0;
    int a[105];

    cin>>n>>d;

    for(i=0; i<n; i++)
        a[i] = 0;

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    sort(a, a+n);

    if(m<=n)
    {
        for(i=0; i<m; i++)
            sum = sum + a[i];
    }
    else
    {
        for(i=0; i<n; i++)
            sum = sum + a[i];
    }

    if(m<=n)
        cout<<sum;
    else
        cout<<(sum-(m-n)*d);

    return 0;
}
