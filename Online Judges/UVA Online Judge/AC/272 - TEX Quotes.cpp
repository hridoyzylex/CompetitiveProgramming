#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("Input.txt", "r", stdin);
    long long i=0;
    char c;

    while(scanf("%c", &c)!=EOF)
    {
        if(c=='"')
        {
            if(i%2==0)
                cout<<"``";
            else
                cout<<"''";

            i++;
        }
        else
            cout<<c;
    }

    return 0;
}
