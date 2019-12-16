#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    //freopen("Input.txt","r",stdin);

    char str[125];
    int i,j,n,flag, stackSize;

    cin>>n;
    getchar();
    for(i=0; i<n; i++)
    {
        stack <char> stk;
        flag = 1;
        gets(str);

        for(j=0; str[j]!='\0'; j++)
        {
            if(str[j]=='(' || str[j]=='[')
            {
                stk.push(str[j]);
            }

            else if(stk.size()!=0)
            {
                if(str[j]==')' && stk.top()=='(')
                {
                    stk.pop();
                }

                else if(str[j]==']' && stk.top()=='[')
                {
                    stk.pop();
                }

                else
                {
                    flag = 0;
                    break;
                }
            }
            else
                break;
        }

        if(stk.size()==0 && str[j]=='\0')
            cout<<"Yes" <<endl;
        else
            cout<<"No" <<endl;

        stk.empty();
    }

    return 0;
}
