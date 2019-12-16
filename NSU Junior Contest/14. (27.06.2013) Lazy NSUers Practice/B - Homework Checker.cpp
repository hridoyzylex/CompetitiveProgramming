#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("B.txt", "r", stdin);

    int a,b,c, correct=0;
    char ch1, ch2, ch3;

    while(cin>>a>>ch1>>b>>ch2>>ch3)
    {
        if(ch3 == '?')
            continue;

        c = ch3 - 48;

        if(ch1 == '+')
        {
            if(a+b==c)
            {
                correct++;
                cout<<a<<"+"<<b<<"="<<c <<" "<<"correct\n";
            }

        }

        if(ch1 == '-')
        {
            if(a-b==c)
            {
                correct++;
                cout<<a<<"-"<<b<<"="<<c <<" "<<"correct\n";
            }
        }
    }

    //cout<<correct<<endl;


    return 0;
}
