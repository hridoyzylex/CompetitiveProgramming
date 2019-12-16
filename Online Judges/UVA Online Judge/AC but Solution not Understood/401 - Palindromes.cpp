#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    //freopen("Input.txt", "r", stdin);
    int i, palindrome, mirrorPalindrome, mirrorString;
    char str[25];

    while(gets(str))
    {
        palindrome = 1;
        mirrorString = 1;

        for(i=0; i<strlen(str); i++)        //to check palindrome
        {
            if(str[i]!=str[strlen(str)-1-i])
            {
                palindrome = 0;
                break;
            }
        }

        for(i=0; i<strlen(str); i++)        //to check mirrored string
        {
            if(str[i]=='A' && str[strlen(str)-1-i]=='A');
            else if (str[i]=='E' && str[strlen(str)-1-i]=='3');
            else if (str[i]=='H' && str[strlen(str)-1-i]=='H');
            else if (str[i]=='I' && str[strlen(str)-1-i]=='I');
            else if (str[i]=='J' && str[strlen(str)-1-i]=='L');
            else if (str[i]=='L' && str[strlen(str)-1-i]=='J');
            else if (str[i]=='M' && str[strlen(str)-1-i]=='M');
            else if (str[i]=='O' && str[strlen(str)-1-i]=='O');
            else if (str[i]=='S' && str[strlen(str)-1-i]=='2');
            else if (str[i]=='T' && str[strlen(str)-1-i]=='T');
            else if (str[i]=='U' && str[strlen(str)-1-i]=='U');
            else if (str[i]=='V' && str[strlen(str)-1-i]=='V');
            else if (str[i]=='W' && str[strlen(str)-1-i]=='W');
            else if (str[i]=='X' && str[strlen(str)-1-i]=='X');
            else if (str[i]=='Y' && str[strlen(str)-1-i]=='Y');
            else if (str[i]=='Z' && str[strlen(str)-1-i]=='5');
            else if (str[i]=='1' && str[strlen(str)-1-i]=='1');
            else if (str[i]=='2' && str[strlen(str)-1-i]=='S');
            else if (str[i]=='3' && str[strlen(str)-1-i]=='E');
            else if (str[i]=='5' && str[strlen(str)-1-i]=='Z');
            else if (str[i]=='8' && str[strlen(str)-1-i]=='8');

            else
            {
                mirrorString = 0;
                break;
            }
        }

        if(!palindrome && !mirrorString)
            cout<<str <<" -- is not a palindrome." <<endl<<endl;
        else if(palindrome && !mirrorString)
            cout<<str <<" -- is a regular palindrome." <<endl<<endl;
        else if(!palindrome && mirrorString)
            cout<<str <<" -- is a mirrored string." <<endl<<endl;
        else if(palindrome && mirrorString)
            cout<<str <<" -- is a mirrored palindrome." <<endl<<endl;

    }

    return 0;
}
