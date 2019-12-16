#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int i;
    char s[7];

    gets(s);
    for(i=0; s[0]!='*'; i++)
    {
        if(s[0]=='H')
            cout<<"Case " <<i+1 <<": Hajj-e-Akbar" <<endl;
        else
            cout<<"Case " <<i+1 <<": Hajj-e-Asghar" <<endl;

        gets(s);
    }
    return 0;
}
