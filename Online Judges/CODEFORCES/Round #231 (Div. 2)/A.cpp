#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("A.txt", "r", stdin);
    int i,stickA=0,stickB=0,stickC=0;
    char ch[305];

    gets(ch);
    for(i=0; ch[i]!='+'; i++)
    {
        if(ch[i]=='|')
            stickA++;
    }
    for( ; ch[i]!='='; i++)
    {
        if(ch[i]=='|')
            stickB++;
    }
    for( ; ch[i]!='\0'; i++)
    {
        if(ch[i]=='|')
            stickC++;
    }

    //cout<<stickA <<" " <<stickB <<" " <<stickC <<endl;

    if(stickA+stickB==stickC)
        printf("%s", ch);
    else if(stickA+stickB==stickC+2)
    {
        if(stickA>1)
        {
            for(i=0; i<stickA-1; i++)
                cout<<"|";
            cout<<"+";
            for(i=0; i<stickB; i++)
                cout<<"|";
            cout<<"=";
            for(i=0; i<stickC+1; i++)
                cout<<"|";
            //cout<<endl;
        }
        else if(stickB>1)
        {
            for(i=0; i<stickA; i++)
                cout<<"|";
            cout<<"+";
            for(i=0; i<stickB-1; i++)
                cout<<"|";
            cout<<"=";
            for(i=0; i<stickC+1; i++)
                cout<<"|";
            //cout<<endl;
        }
    }
    else if(stickA+stickB==stickC-2)
    {
        if(stickC>1)
        {
            for(i=0; i<stickA+1; i++)
                cout<<"|";
            cout<<"+";
            for(i=0; i<stickB; i++)
                cout<<"|";
            cout<<"=";
            for(i=0; i<stickC-1; i++)
                cout<<"|";
            //cout<<endl;
        }
    }
    else
        cout<<"Impossible";

    return 0;
}
