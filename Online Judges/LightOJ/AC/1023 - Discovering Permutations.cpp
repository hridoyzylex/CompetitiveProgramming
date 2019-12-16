#include<iostream>
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int i,j,n,k,T;
    int a[30];

    cin>>T;
    for(j=0; j<T; j++)
    {
        cin>>n>>k;
        for (i=0; i<n; i++)
            a[i] = i;

        cout<<"Case " <<j+1 <<":" <<endl;

        while (k--)
        {
            for (i=0; i<n; i++)
                printf ("%c", a[i]+'A');

            cout<<endl;

            if(!next_permutation (a,a+n))
                break;
        }
    }
    return 0;
}
