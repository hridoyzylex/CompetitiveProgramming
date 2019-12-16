#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,k;
    char a[105];
    char b[105];

    gets(a);

    for(i=0, j=0; a[i]!='\0'; i++)
    {
        if(a[i]!='+')
        {
            b[j] = a[i];
            j++;
        }
    }

    sort (b, b+j);

    for(i=0; i<j; i++)
    {
        cout<<b[i];

        if(i<j-1)
            cout<<"+";
    }
        cout<<endl;

    return 0;
}
