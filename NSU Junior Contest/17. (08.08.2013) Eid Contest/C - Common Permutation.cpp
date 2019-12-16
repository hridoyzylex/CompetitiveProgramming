#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("C.txt", "r", stdin);

    int i,j,k;
    char a[1005];
    char b[1005];
    char c[1005];

    while(gets(a), gets(b))
    {
        k=0;
        for(i=0; a[i]!='\0'; i++)
        {
            for(j=0; b[j]!='\0'; j++)
            {
                if(a[i]==b[j])
                {
                    c[k] = a[i];
                    k++;
                    break;
                }
            }
        }

        sort (c, c+k);

        /*for(i=0; i<k-1; )
        {
            if(c[i]==c[i+1])
            {
                c[i] = c[k-1];
                k--;
                sort(c, c+k);
            }
            else
                i++;
        }*/

        for(int l=0; l<k; l++)
            cout<<c[l];
            cout<<endl;
    }

    return 0;
}
