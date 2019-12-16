#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i,j=0;
    char S[101];
    char W[6];

    for(int i=0; i<6; i++)
        W[i] = 'a';

    gets(S);
    for(i=0; S[i]!='\0'; i++)
    {
        if(S[i]=='h')
        {
            W[j] = 'h';
            j++;
            break;
        }
    }

    for(i=i+1; S[i]!='\0'; i++)
    {
        if(S[i]=='e')
        {
            W[j] = 'e';
            j++;
            break;
        }
    }

    for(i=i+1; S[i]!='\0'; i++)
    {
        if(S[i]=='l')
        {
            W[j] = 'l';
            j++;
            break;
        }
    }

    for(i=i+1; S[i]!='\0'; i++)
    {
        if(S[i]=='l')
        {
            W[j] = 'l';
            j++;
            break;
        }
    }

    for(i=i+1; S[i]!='\0'; i++)
    {
        if(S[i]=='o')
        {
            W[j] = 'o';
            j++;
            break;
        }
    }

    if(W[0]=='h' && W[1]=='e' && W[2]=='l' && W[3]=='l' && W[4]=='o')
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
