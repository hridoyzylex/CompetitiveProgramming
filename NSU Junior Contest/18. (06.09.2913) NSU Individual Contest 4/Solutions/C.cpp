#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    freopen ("C.txt", "r", stdin);
    int T, n, i,j,k;
    int a[10];
    int b[10];
    int product = 0;

    cin>>T;
    for(i=0; i<T; i++)
    {
        product = 0;
        cin>>n;
        for(j=0; j<n; j++)
        {
            cin>>a[j];
        }

        for(j=0; j<n; j++)
        {
            cin>>b[j];
        }

        sort(a, a+n);
        sort(b, b+n);

        /*for(j=0; j<n; j++)
        {
            cout<<a[j];
        }
        cout<<endl;

        for(j=0; j<n; j++)
        {
            cout<<b[j];
        }
        cout<<endl;*/

        for(k=0; k<n; k++)
        {
            product = product + ( a[k] * b[n-k-1] );
        }

        cout<<"Case #" <<i+1 <<": " <<product <<endl;
    }

    return 0;
}
