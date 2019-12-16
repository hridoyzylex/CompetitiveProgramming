#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    freopen("G.txt", "r", stdin);
    int i,j,T, spring, winter;
    char dummy[5];


    cin>>T;
    gets(dummy);
    for (i=0; i<T; i++)
    {
        spring = 0;
        winter = 0;
        char a[50] = {0};
        gets(a);

        for (j=0; j<strlen(a)-1; j++)
        {
            if ((a[j]=='S')&&(a[j+1]=='S'))
                spring++;
            if ((a[j]=='S')&&(a[j+1]!='S'))
                winter++;
        }
        cout<<"Case " <<i+1 <<": " <<spring <<" / " <<winter <<endl;
    }

    return 0;
}
