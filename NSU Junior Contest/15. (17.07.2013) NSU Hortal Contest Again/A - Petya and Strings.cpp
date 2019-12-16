#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int i, sumA = 0, sumB = 0, difference = 0;
    char a[105];
    char b[105];

    gets(a);
    gets(b);

    for(i=0; i<strlen(a); i++)
    {
        if(a[i]>='a' && a[i]<='z')
            sumA = sumA + a[i];
        else if(a[i]>='A' && a[i]<='Z')
            sumA = sumA + a[i] + 32;


        if(b[i]>='a' && b[i]<='z')
            sumB = sumB + b[i];
        else if(b[i]>='A' && b[i]<='Z')
            sumB = sumB + b[i] + 32;

    }

    difference = sumA-sumB;

    if(difference>0)
        cout<<"1"<<endl;
    else if(difference<0)
        cout<<"-1"<<endl;
    if(difference==0)
        cout<<"0"<<endl;

    return 0;
}
