#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    freopen("F.txt", "r", stdin);

    int i;
    char a[1000];

    while(gets(a))
    {
        for(i=0; a[i]!='\0'; i++)
        {
            printf("%c", a[i]-7);
        }
        cout<<endl;
    }
    return 0;
}
