#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int i, T;
    long long n;
    char s[7];

    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n>>s;

        if(strcmp(s,"Alice")==0)
        {
            if(n%3==1)
                cout<<"Case " <<i+1 <<": Bob" <<endl;
            else
                cout<<"Case " <<i+1 <<": Alice" <<endl;
        }
        else
        {
            if(n%3==0)
                cout<<"Case " <<i+1 <<": Alice" <<endl;
            else
                cout<<"Case " <<i+1 <<": Bob" <<endl;
        }
    }
    return 0;
}
