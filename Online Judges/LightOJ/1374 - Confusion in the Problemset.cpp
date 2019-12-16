#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int i,j,k,T,n,flag;
    int a[ 10005];

    cin>>T;
    for(i=0; i<T; i++)
    {
        flag = 0;

        cin>>n;
        for(j=0; j<n; j++)
        {
            cin>>a[j];
        }

        for(j=0; j<n; j++)
        {
            cout<<a[j] <<" - " <<j <<", " <<n-j-1 <<endl;

            if(a[j]==j || a[j]==n-j-1)
            {
                flag=1;
            }


            else
            {
                flag=0;
                break;
            }
        }

        if(flag)
            cout<<"Case " <<i+1 <<": yes" <<endl;
        else
            cout<<"Case " <<i+1 <<": no" <<endl;


    }

    return 0;
}
