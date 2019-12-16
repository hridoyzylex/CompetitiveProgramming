#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("A.txt", "r", stdin);
    int n,i,j,k,l,counter;
    int a[100000];
    int b[3];

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n);

    for(i=0,k=0; (i<n)||(a[i]!=8); i++)
    {
        for(j=i+1; (j<n)||(a[j]!=8); j++)
        {
            if(a[j] % a[i] == 0)
            {
               b[k]=a[i];
               k++;
               a[i] = 8;
               i=j;
               sort(a, a+n);
               counter++;
            }
            if(counter==3)
            {
                for(l=0; l<3; l++)
                    cout<<b[l] <<" ";
                    cout<<endl;

                    counter = 0;
                    k = 0;
            }
        }
    }



    return 0;
}
