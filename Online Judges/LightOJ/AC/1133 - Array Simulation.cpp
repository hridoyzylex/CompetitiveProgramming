#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int i,j,k,T,x,n,m,oper,temp,y,z;
    int a[101];
    char c;

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n>>m;
        for(j=0; j<n; j++)
        {
            cin>>x;
            a[j] = x;
        }

        for(j=0; j<m; j++)
        {
            cin>>c;
            if(c=='S')
            {
                cin>>oper;
                for(k=0; k<n; k++)
                {
                    a[k] = a[k] + oper;
                }
            }

            else if(c=='M')
            {
                cin>>oper;
                for(k=0; k<n; k++)
                {
                    a[k] = a[k] * oper;
                }
            }

            else if(c=='D')
            {
                cin>>oper;
                for(k=0; k<n; k++)
                {
                    a[k] = a[k] / oper;
                }
            }

            else if(c=='R')
            {
                for(k=0; k<n/2; k++)
                {
                    temp = a[k];
                    a[k] = a[n-k-1];
                    a[n-k-1] = temp;
                }
            }

            else if(c=='P')
            {
                cin>>y>>z;
                temp = a[y];
                a[y] = a[z];
                a[z] = temp;
            }
        }
        cout<<"Case " <<i+1 <<":" <<endl;
        for(k=0; k<n-1; k++)
            cout<<a[k] <<" ";
        cout<<a[k] <<endl;

    }

    return 0;
}
